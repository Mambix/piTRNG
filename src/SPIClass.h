
#ifndef SPI_CLASS_H
#define SPI_CLASS_H

#include <string>
#include <bcm2835.h>
#include "EntropyClass.h"

using namespace std;
/* SPI Class
 * Purpose: Read Entropy and return it to user
 */
class SPIClass
{
private:
    EntropyClass* Entropy;
public:
    SPIClass();
    virtual ~SPIClass();
    uint16_t ReadRAW();
    uint8_t Read();
//    void ReadManyTimes(char* data, int size);
    void Start();
    void Stop();
};

#endif
