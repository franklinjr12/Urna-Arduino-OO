#include "Memory.h"


//*************************************************************************************
// EEPROM class

EEPROM::EEPROM(int memorySize){
    if(memorySize < 1) return -1;
    dataList = new char[memorySize];
}

//*************************************************************************************

//*************************************************************************************
// MemoryFactory class
GenericMemory* MemoryFactory::createMemory(int memorySize){
    if(memorySize < 1) return 0;
    GenericMemory* memo = new GenericMemory(memorySize);
    return memo;
}

GenericMemory* MemoryFactory::createMemory(){
    GenericMemory* memo = new GenericMemory(1024);
    return memo;
}
//*************************************************************************************
