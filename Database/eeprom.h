/*
 * Simulador de EEPROM para arduino feito em C++
 * Simulation of and EEPROM to help tests.
 */
#ifndef EEPROM_H
#define EEPROM_H

// TESTED
// OK

//***********************************************************************
class EEPROM{

/*
 * The EEPROM is just a list,
 * where each space takes a char,
 * a byte from 0 to 255.
 */


private:

public:

    //==================================================================================================
    //used to construct an EEPROM, takes as parameter the amount of memory it has
    EEPROM(int memSize);
    //==================================================================================================

    //==================================================================================================
    // Amount of memory the EEPROM has to store data.
    // Used to create the dataList.
    int memorySize;
    //==================================================================================================

    //==================================================================================================
    //array of data
    char* dataList;
    //==================================================================================================


    /*
    //writes data to the current valid position of EEPROM pointed by memoryPointer
    //return 0 on success and 1 on failure
    int write(char data, int pos);

    //reads the data from the position pointed by pos
    //returns '!' on failure
    char read(int pos);

    int sizeEEPROM();
    */

};
//***********************************************************************






//***********************************************************************
class EEPROMFactory{
public:

    /*
     * Class used to create an EEPROM object
     * necessery to pass the amount of memory that the EEPROM has
     * returns the adress of an EEPROM object.
     * Obs: Every method returns 0 on success
     */

    EEPROM* createEEPROM(int memSize);

    //creates a default EEPROM with size 1024
    EEPROM* createEEPROM(void);

};
//***********************************************************************

#endif
