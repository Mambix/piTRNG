#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "EntropyClass.h"

using namespace std;

EntropyClass::EntropyClass()
{
	this->CE = new GPIOClass("4");
    this->CE->export_gpio();
    this->CE->setdir_gpio("out");
}

void EntropyClass::Start()
{
	this->CE->setval_gpio("1");
}

void EntropyClass::Stop()
{
	this->CE->setval_gpio("0");
}