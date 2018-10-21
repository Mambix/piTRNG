// Compile with: g++ -Wall spiBB.cpp ../src/ADS7883Class.cpp ../src/EntropyClass.cpp ../GPIO/GPIOClass.cpp -o testBBSPI

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/ADS7883Class.h"

int main (void)
{
    cout << "Begin" << endl;

    ADS7883Class* spi = new ADS7883Class();

    cout << "Init SPI..." << endl;

    spi->Start();
    // usleep(1000000);

    cout << "Reading 8bit..." << endl;
    char data_buffer[100];
    for (int i=0; i<100; i++) {
        data_buffer[i] = spi->Read();
    }
    
    cout << "8bit Data:" << endl;
    int l=0;
    for (int i=0; i<100; i++, l++) {
        printf("%02hhX ", data_buffer[i]);
        if (l == 9) {
            cout << endl;
            l=-1;
        }
    }
    cout << endl;

    cout << "Reading RAW..." << endl;
    uint16_t data_buffer_raw[100];
    for (int i=0; i<100; i++) {
        data_buffer_raw[i] = spi->ReadRAW();
    }

    cout << "RAW Data:" << endl;
    l=0;
    for (int i=0; i<100; i++, l++) {
        printf("%04hhhhX ", data_buffer_raw[i]);
        if (l == 9) {
            cout << endl;
            l=-1;
        }
    }
    cout << endl;

    spi->Stop();
    delete spi;

    cout << "Done!" << endl;

    return 0;
}
