
#ifndef EEPROMMANIPULATOR_H
#define EEPROMMANIPULATOR_H
#include "../eeprom.h"


/*
 * Class used to the user be able to operate easily the EEPROM simulation class
 * Obs: Every method returns 0 on success
 */

 //****************************************************************************************************
class GenericEEPROMManipulator{

 /*
  * Generoc class that controls an EEPROM object.
  * Able just to read and write bytes into it.
  * Necessary to create real classes to manipulate EEPROM and control the memory.
  */

private:

    // Chip the Manipulator controls
    EEPROM* memory;

public:

     //================================================================================================
     // Writes a character at specific position of EEPROM
     virtual int writeCharToMemory(char letter, int position) = 0;
     //================================================================================================


     //================================================================================================
     // Reads the character at specific position of EEPROM
     virtual char readCharFromMemory(int position) = 0;
     //================================================================================================

     //================================================================================================
     // Give the manipulator an EEPROM for it to operate
     virtual int assingEEPROMToManipulator(EEPROM* eepromChip) = 0;
     //================================================================================================

};
//****************************************************************************************************



//****************************************************************************************************
class EEPROMManipulatorSimulation : public GenericEEPROMManipulator{

    /*
     * Class used to test the program
     */

public:

    //===================================================================
    // just giving body to GenericEEPROMManipulator for tests
    int writeCharToMemory(char letter, int position);
    char readCharFromMemory(int position);
    int assingEEPROMToManipulator(EEPROM* eepromChip);
    //===================================================================
};
//****************************************************************************************************




 /*
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
*/
#endif // EEPROMMANIPULATOR_H
