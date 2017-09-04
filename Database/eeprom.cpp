#include "../Headers/eeprom.h"

EEPROM* EEPROMFactory::createEEPROM(int memSize){
    EEPROM* e1 = new EEPROM(memSize);
    return e1;
}

EEPROM::EEPROM(int memSize){
    memorySize = memSize;
    memoryPointer = 0;
    dataList = new char[memorySize];
}

char EEPROM::read(int mem){
    if(mem > memoryPointer) return '!';
    return dataList[mem];
}

int EEPROM::write(char data){
    if(memoryPointer >= memorySize) return 0;
}
