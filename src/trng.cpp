#include "LEDClass.h"
#include "SPIClass.h"

using namespace std;
// g++ -Wall trng.cpp SPIClass.cpp EntropyClass.cpp LEDClass.cpp -lbcm2835 -o trng

int main (void)
{
    LEDClass* LED = new LEDClass();
    SPIClass* SPI = new SPIClass();  

    return 0;
}
