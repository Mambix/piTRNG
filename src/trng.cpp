#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "LEDClass.h"
#include "SPIClass.h"

using namespace std;
// Compile with: g++ -Wall trng.cpp ../src/SPIClass.cpp ../src/LEDClass.cpp ../src/EntropyClass.cpp ../GPIO/GPIOClass.cpp -lbcm2835 -o readTRNG

int main (void)
{
    SPIClass* spi = new SPIClass();
    spi->Start();

    uint32_t size = 100000;

    char data_buffer[size];
    for (uint32_t i=0; i<size; i++) {
        data_buffer[i] = spi->Read();
    }
    
    for (uint32_t i=0; i<size; i++) {
        cout << data_buffer[i];
    }

    spi->Stop();
    delete spi;

    return 0;
}
