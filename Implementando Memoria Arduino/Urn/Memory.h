/*
 * Simulador de memoria para arduino feito em C++
 * Simulation of and memory to help tests.
 */
#ifndef EEPROM_H
#define EEPROM_H

#include "Arduino.h"


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
    //GenericMemory(int memorySize);
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


};
//***********************************************************************



//***********************************************************************
/*
class EEPROM : public GenericMemory{

     //Class that represents an EEPROM of arduino
    public:
    EEPROM(int memorySize);
};
*/
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

    Memory* createMemory(int memorySize);

    //creates a default Memory with size 1024B
    Memory* createMemory(void);

    //specific for arduino, because it doesn't need to allocate the bytes
    Memory* createMemoryArduino(int memorySize);

};
//***********************************************************************

#endif
