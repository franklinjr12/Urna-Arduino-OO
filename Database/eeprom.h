/*
 * Simulador de EEPROM para arduino feito em C++
 */
#ifndef EEPROM_H
#define EEPROM_H
class EEPROM{

private:
    unsigned int memorySize;    //amount of memory the EEPROM has to store data
    unsigned int memoryPointer; //pointer to the current position of free space on EEPROM's memory
    char* dataList;             //array of data

public:
    //used to construct an EEPROM, takes as parameter the amount of memory it has
    EEPROM(int memSize);

    //writes data to the current valid position of EEPROM pointed by memoryPointer
    int write(char data);

    //reads the data from the position pointed by mem
    char read(int mem);
};

class EEPROMFactory{
public:
    /*
     * Method used to create an EEPROM object
     * necessery to pass the amount of memory that the EEPROM has
     * returns the adress of an EEPROM object.
     */
    EEPROM* createEEPROM(int memSize);
};
#endif
