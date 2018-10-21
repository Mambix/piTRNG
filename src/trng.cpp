#include "LEDClass.h"
#include "SPIClass.h"

using namespace std;
// Compile with: g++ -Wall trng.cpp ../src/SPIClass.cpp ../src/LEDClass.cpp ../src/EntropyClass.cpp ../GPIO/GPIOClass.cpp -lbcm2835 -o readTRNG

int main (void)
{
    SPIClass* SPI = new SPIClass();  

    return 0;
}
