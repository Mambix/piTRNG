#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "LEDClass.h"

using namespace std;

LEDClass::LEDClass()
{
	this->rLED = new GPIOClass("17");
    this->gLED = new GPIOClass("27");
    this->yLED = new GPIOClass("22");

    this->rLED->export_gpio();
    this->gLED->export_gpio();
    this->yLED->export_gpio();

    this->rLED->setdir_gpio("out");
    this->gLED->setdir_gpio("out");
    this->yLED->setdir_gpio("out");
}

void LEDClass::ON(int index)
{
	this->LEDs[index]->setval_gpio("1");
}

void LEDClass::OFF(int index)
{
	this->LEDs[index]->setval_gpio("0");
}
