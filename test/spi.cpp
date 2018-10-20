// Compile with: g++ -Wall spi.cpp ../src/SPIClass.cpp ../src/EntropyClass.cpp ../GPIO/GPIOClass.cpp -lbcm2835 -o testSPI

#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/SPIClass.h"

// g++ -Wall spi.cpp -lbcm2835 -o spi

int main (void)
{
    SPIClass* spi = new SPIClass();

    spi->Start();
    usleep(1000000);

    char* data = spi->ReadManyTimes(100);
    
    cout << "Data:" << endl;
    for (int i=0; i<100; i++) {
	cout << *data << endl;
	data++;
    }
    delete[] data;

    spi->Stop();

    return 0;
}
