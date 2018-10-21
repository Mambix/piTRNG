#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "ADS7883Class.h"

using namespace std;

ADS7883Class::ADS7883Class()
{
    this->Entropy = new EntropyClass();
    this->Entropy->Stop();

    this->CS = new GPIOClass("17");
    this->SDI = new GPIOClass("27");
    this->CLK = new GPIOClass("22");

    this->CS->export_gpio();
    this->SDI->export_gpio();
    this->CLK->export_gpio();

    this->CS->setdir_gpio("out");
    this->SDI->setdir_gpio("in");
    this->CLK->setdir_gpio("out");

    this->CS->setval_gpio("1");
    this->CLK->setval_gpio("1");

    this->delay = 5000; //5ms -> 
}

void ADS7883Class::wait() {
    usleep(this->delay);
}

string ADS7883Class::readBIT() {
    string inputstate;
    this->wait();
    this->CLK->setval_gpio("0");
    this->SDI->getval_gpio(inputstate);
    this->wait();
    this->CLK->setval_gpio("1");
    return inputstate;
}

void ADS7883Class::PowerUP()
{
    for (int i=0; i<4; i++) {
        this->ReadRAW();
    }
}

int ADS7883Class::ReadRAW()
{
    int i, data = 0;
    string sData;
    
    this->CS->setval_gpio("0");
    for (i=0; i<14; i++) {
        data = data << 1;
        sData = this->readBIT();
        if (sData == "1") {
            data |= 1;
        }
    }
    for (i=0; i<2; i++) {
        sData = this->readBIT();
    }
    this->CS->setval_gpio("1");

    return data;
}

char ADS7883Class::Read()
{
    char ret = this->ReadRAW() && 0xff;
    return ret;
}

void ADS7883Class::Start()
{
    this->Entropy->Start();
    // Power up device
    // Make 4 dummy reads
    for (int i=0; i<4; i++) {
        this->ReadRAW();
    }
}

void ADS7883Class::Stop()
{
    this->Entropy->Stop();
}
