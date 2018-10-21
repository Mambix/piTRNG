#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "ADS7883Class.h"

using namespace std;

ADS7883Class::ADS7883Class() {
    this->Entropy = new EntropyClass();
    this->Entropy->Stop();

    this->CS = new GPIOClass("8");
    this->SDI = new GPIOClass("9");
    this->CLK = new GPIOClass("11");

    this->CS->export_gpio();
    this->SDI->export_gpio();
    this->CLK->export_gpio();

    this->CS->setdir_gpio("out");
    this->SDI->setdir_gpio("in");
    this->CLK->setdir_gpio("out");

    this->CS->setval_gpio("1");
    this->CLK->setval_gpio("0");

    this->delay = 1; //50us -> 
}

ADS7883Class::~ADS7883Class() {
    this->Entropy->Stop();
}

void ADS7883Class::wait() {
    usleep(this->delay);
}

string ADS7883Class::readBIT(bool low) {
    string inputstate;
    this->wait();
    this->CLK->setval_gpio("0");
    this->SDI->getval_gpio(inputstate);
    this->wait();
    if (low) {
        this->CLK->setval_gpio("1");
    }
    cout << inputstate;
    return inputstate;
}

void ADS7883Class::PowerUP()
{
    for (int i=0; i<4; i++) {
        this->ReadRAW();
    }
}

uint16_t ADS7883Class::ReadRAW()
{
    int i;
    uint16_t data = 0;
    string sData;
    
    this->CLK->setval_gpio("1");
    this->CS->setval_gpio("0");
    for (i=0; i<16; i++) {
        data = data << 1;
        sData = this->readBIT(i!=15);
        if (sData == "1") {
            data |= (uint16_t)1;
        }
    }
    this->CS->setval_gpio("1");

    cout << endl;

    return data;
}

uint8_t ADS7883Class::Read()
{
    uint8_t ret = (this->ReadRAW() >> 2) & 0xff;
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
