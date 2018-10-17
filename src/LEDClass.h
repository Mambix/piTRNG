
#ifndef LED_CLASS_H
#define LED_CLASS_H

#include <string>
#include "../GPIO/GPIOClass.h"

using namespace std;
/* LED Class
 * Purpose: Control LEDs on board
 */
class LEDClass
{
private:
    GPIOClass* rLED = new GPIOClass("17");
    GPIOClass* gLED = new GPIOClass("27");
    GPIOClass* yLED = new GPIOClass("22");
    GPIOClass* LEDs[3] = {rLED, gLED, yLED};
public:
	LEDClass();

    void ON(int idxex) {};
    void OFF(int index) {};
};

#endif
