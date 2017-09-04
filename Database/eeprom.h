/*
 * Simulador de EEPROM para arduino feito em C++
 * Simulation of and EEPROM to help tests.
 */
#ifndef EEPROM_H
#define EEPROM_H

/*
 *
 */

class EEPROM{

private:
    int memorySize;    //amount of memory the EEPROM has to store data
    //int memoryPointer; //pointer to the current position of free space on EEPROM's memory
    char* dataList;             //array of data

public:
    //used to construct an EEPROM, takes as parameter the amount of memory it has
    EEPROM(int memSize);

    //writes data to the current valid position of EEPROM pointed by memoryPointer
    //return 0 on success and 1 on failure
    int write(char data, int pos);

    //reads the data from the position pointed by pos
    //returns '!' on failure
    char read(int pos);

    int sizeEEPROM();

};

class EEPROMFactory{
public:
    /*
     * Method used to create an EEPROM object
     * necessery to pass the amount of memory that the EEPROM has
     * returns the adress of an EEPROM object.
     */
    EEPROM* createEEPROM(int memSize);
    EEPROM* createEEPROM(void); //creates a default EEPROM with size 1024
};
#endif
