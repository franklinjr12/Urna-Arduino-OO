
#ifndef EEPROMMANIPULATOR_H
#define EEPROMMANIPULATOR_H

/*
 * Class used to the user be able to operate easily the EEPROM simulation class
 * Obs: Every method returns 0 on success
 */

// COMMENTING JUST TO COMPILE MAIN


/*

 //****************************************************************************************************
class GenericMemoryManipulator{

  //BEGIN THIS COMMENT
  * Generoc class that controls an EEPROM object.
  * Able just to read and write bytes into it.
  * Necessary to create real classes to manipulate EEPROM and control the memory.
  // END THIS COMMENT

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
class MemoryManipulatorSimulation : public GenericMemoryManipulator{

    /*
     * Class used to test the program
    //END THIS COMMENT

public:

    //===================================================================
    // just giving body to GenericEEPROMManipulator for tests
    int writeCharToMemory(char letter, int position);
    char readCharFromMemory(int position);
    int assingEEPROMToManipulator(EEPROM* eepromChip);
    //===================================================================
};
//****************************************************************************************************

//****************************************************************************************************
class GenericUrnDatabaseSetup{
 //BEGIN THIS COMMENT
 * Class used to make the setup of the memory
 //END THIS COMMENT

private:
    GenericEEPROMManipulator* memoryControler;
public:
    virtual int assingManipulator(GenericEEPROMManipulator* controler) = 0;
};


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
