
#ifndef ENTROPY_CLASS_H
#define ENTROPY_CLASS_H

#include <string>
#include "../GPIO/GPIOClass.h"

using namespace std;
/* Entropy Class
 * Purpose: Enable/Disable Entropy Pool
 * 
 * Is used to enable/disable entropy pools power supply.
 * When chip enable pin (CE) is High entropy pool is generating random data.
 */
class EntropyClass
{
private:
    GPIOClass* CE;

public:
	EntropyClass();

    void Start();
    void Stop();
};

#endif
