#include "Memory.h"


//*************************************************************************************
// EEPROM class

/*

EEPROM::EEPROM(int memorySize){
    if(memorySize < 1) return -1;
    dataList = new char[memorySize];
}

*/

//*************************************************************************************

//*************************************************************************************
// MemoryFactory class
Memory* MemoryFactory::createMemory(int memorySize){
    if(memorySize < 1) return 0;
    Memory* memo = new Memory;
    memo->dataList = new char[memorySize];
    return memo;
}

Memory* MemoryFactory::createMemory(){
    Memory* memo = new Memory;
    memo->memorySize = 1024;
    memo->dataList = new char[1024];
    return memo;
}

Memory* MemoryFactory::createMemoryArduino(int memorySize){
    Memory* memo = new Memory;
    memo->memorySize = memorySize;
    memo->dataList = new char[1];   //just no to be null
}
//*************************************************************************************
