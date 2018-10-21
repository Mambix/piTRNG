
#ifndef ADS7883_CLASS_H
#define ADS7883_CLASS_H

#include <string>
#include "../GPIO/GPIOClass.h"
#include "EntropyClass.h"

using namespace std;
/* ADS7883 Class
 * Purpose: Read entropy data from ADC
 */
class ADS7883Class {
private:
    GPIOClass* CS;
    GPIOClass* SDI;
    GPIOClass* CLK;
    EntropyClass* Entropy;
    uint32_t delay;
    void wait();
    string readBIT();
public:
    ADS7883Class();
    ~ADS7883Class();

    void PowerUP();
    uint16_t ReadRAW();
    uint8_t Read();

    void Start();
    void Stop();
};

#endif
