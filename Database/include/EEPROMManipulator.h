#ifndef EEPROMMANIPULATOR_H
#define EEPROMMANIPULATOR_H
#include "../eeprom.h"
#include <string>


using namespace std;
/*
 * Class used to the user be able to operate easily the EEPROM simulation class
 */

class EEPROMManipulator
{
    public:

        //used to make an instance of an EEPROMManipulator
        //takes an EEPROM as paramater for it to use
        EEPROMManipulator(EEPROM* ep1);

        //writes a vector of data into the EEPROM
        //returns 0 on success and 1 on failure
        int writeDataBlock(char* vectorData, int size, int pos);

        //writes a single character at the specific position
        int writeData(char letter, int pos);

        //writes '!' in all poosition on EEPROM's memory
        int eraseAllData();

        //Reads the data in the pos
        char readData(int pos);

        //Reades the data from pos to end
        char* readDataBlock(int pos, int end);

    protected:

    private:

        EEPROM* simulatedEEPROM;
        int memControl;

};

#endif // EEPROMMANIPULATOR_H
