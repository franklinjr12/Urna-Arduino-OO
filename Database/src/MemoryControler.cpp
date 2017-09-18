#include "MemoryControler.h"

//****************************************************************
//implementations of memoryControlerTest

int MemoryControlerTest::write(char letter, int position){

    // errors check
    if(memoryAssigned == 0) return -1;
    if(position > memoryAssigned->memorySize) return -1;

    memoryAssigned->dataList[position] = letter;

    return 0;
}

char MemoryControlerTest::read(int position){
    // errors check
    // the char '!' represents failure
    if(memoryAssigned == 0) return '!';
    if(position > memoryAssigned->memorySize) return '!';

    return memoryAssigned->dataList[position];
}

int MemoryControlerTest::assign(Memory* mem){
    memoryAssigned = mem;
    return 0;
}
//****************************************************************
