/*
 * Simulador de EEPROM para arduino feito em C++
 * Simulation of and EEPROM to help tests.
 */
#ifndef EEPROM_H
#define EEPROM_H

//##########################################
// NOT BEING USED ANYMORE
//##########################################

//***********************************************************************
class Memory{

/*
 * The Memory is just a list,
 * where each space takes a char,
 * a byte from 0 to 255.
 */


private:

public:

    //==================================================================================================
    //used to construct an Memory, takes as parameter the amount of bytes it has
    Memory(int memSize);
    //==================================================================================================

    //==================================================================================================
    // Amount of bytes the Memory has to store data.
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
class MemoryFactory{
public:

    /*
     * Class used to create an Memory object
     * necessery to pass the amount of bytes that the Memory has
     * returns the adress of an Memory object.
     * Obs: Every method returns 0 on success
     */

    Memory* createMemory(int memSize);

    //creates a default Memory with size 1024B
    Memory* createMemory(void);

};
//***********************************************************************

#endif
