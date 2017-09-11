#include "eeprom.h"

// EEPROMFactory methods

//==================================================================================================
// Returns an EEPROM object with memory defined by memSize
EEPROM* EEPROMFactory::createEEPROM(int memSize){
    EEPROM* e1 = new EEPROM(memSize);
    return e1;
}
//==================================================================================================


//==================================================================================================
// Returns an default EEPROM object with memory size of 1024 bytes
EEPROM* EEPROMFactory::createEEPROM(){
    EEPROM* e1 = new EEPROM(1024);
    return e1;
}
//==================================================================================================


EEPROM::EEPROM(int memSize){
    memorySize = memSize;
    dataList = new char[memorySize];
}

char EEPROM::read(int pos){
    if(pos > memorySize) return '!';
    return dataList[pos];
}

int EEPROM::write(char data, int pos){
    if(pos >= memorySize) return 1;
    dataList[pos] = data;
    return 0;
}

int EEPROM::sizeEEPROM(){
    return memorySize;
}
