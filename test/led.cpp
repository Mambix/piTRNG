// Compile with: g++ -Wall led.cpp ../src/LEDClass.cpp ../GPIO/GPIOClass.cpp -o testLED

#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/LEDClass.h"

using namespace std;

int main (void)
{
    string inputstate;
    LEDClass* LEDs = new LEDClass();

    while(1)
    {
        int j=2;
        for (int i=0; i<3; i++, j++) {
            LEDs->ON(i);
            LEDs->OFF(j%3);
            usleep(100000);  // wait for 0.1 seconds
        }
    }
    cout << "Exiting....." << endl;
    return 0;
}
