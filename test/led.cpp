#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../GPIO/GPIOClass.h"

using namespace std;

int main (void)
{
    string inputstate;
    GPIOClass* rLED = new GPIOClass("17");
    GPIOClass* gLED = new GPIOClass("27");
    GPIOClass* yLED = new GPIOClass("22");
    GPIOClass* LEDs[3] = {rLED, gLED, yLED};

    // Export pins
    rLED->export_gpio();
    gLED->export_gpio();
    yLED->export_gpio();

    cout << " GPIO pins exported" << endl;

    rLED->setdir_gpio("out");
    gLED->setdir_gpio("out");
    yLED->setdir_gpio("out");

    cout << " Set GPIO pin directions" << endl;

    while(1)
    {
        int j=2;
        for (int i=0; i<3; i++, j++) {
            LEDs[i]->setval_gpio("1");
            LEDs[j%3]->setval_gpio("0");
            usleep(100000);  // wait for 0.5 seconds
        }
    }
    cout << "Exiting....." << endl;
    return 0;
}