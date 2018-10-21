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
    usleep(250000);

    uint32_t size = 1024 * 1024;

    char data_buffer[size];
    for (int i=0; i<size; i++) {
        data_buffer[i] = spi->Read();
    }
    
    for (uint32_t i=0; i<size; i++) {
        cout << data_buffer[i];
    }

    spi->Stop();
    delete spi;

    return 0;
}
