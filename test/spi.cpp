// Compile with: g++ -Wall spi.cpp ../src/SPIClass.cpp ../src/EntropyClass.cpp ../GPIO/GPIOClass.cpp -lbcm2835 -o testSPI

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/SPIClass.h"

// g++ -Wall spi.cpp -lbcm2835 -o spi

int main (void)
{
    cout << "Begin" << endl;

    SPIClass* spi = new SPIClass();

    cout << "Init SPI..." << endl;

    spi->Start();
    usleep(1000000);

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
    int data_buffer_raw[100];
    for (int i=0; i<100; i++) {
        data_buffer_raw[i] = spi->ReadRAW();
    }

    cout << "RAW Data:" << endl;
    l=0;
    for (int i=0; i<100; i++, l++) {
        printf("%04hhX ", data_buffer_raw[i]);
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
