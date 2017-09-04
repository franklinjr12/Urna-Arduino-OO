#include "eeprom.h"

EEPROM* EEPROMFactory::createEEPROM(int memSize){
    EEPROM* e1 = new EEPROM(memSize);
    return e1;
}

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
