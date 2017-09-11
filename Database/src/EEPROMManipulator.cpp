#include "EEPROMManipulator.h"

/*

//********************************************************************************************************
// Methods from EEPROMManipulatorSimulation

//========================================================================================================
int EEPROMManipulatorSimulation::writeCharToMemory(char letter, int position){
    if(memory == 0) return -1;  //case the manipulator has no EEPROM assingned to it
    if(memory->memorySize < position) return -1; //case the position doesnt exists in the memory
    memory->dataList[position] = letter;
    return 0;
}
//========================================================================================================


//========================================================================================================
char EEPROMManipulatorSimulation::readCharFromMemory(int position){
    if(memory->memorySize < position) return '\0'; //case the position doesnt exists in the memory
    return memory->dataList[position];
}
//========================================================================================================



//========================================================================================================
int EEPROMManipulatorSimulation::assingEEPROMToManipulator(EEPROM* eepromChip){
    if(eepromChip == 0) return -1;
    memory = eepromChip;
    return 0;
}
//========================================================================================================

//********************************************************************************************************

/*

EEPROMManipulator::EEPROMManipulator(EEPROM* ep1){
    simulatedEEPROM = ep1;
    memControl = 0;
}

int EEPROMManipulator::eraseAllData(){
    for(int i = 0; i < simulatedEEPROM->sizeEEPROM(); i++){
        simulatedEEPROM->write('!', i); //'!' is used to indicate nothing in the space
    }
    memControl = 0; //indicates that all memory of EEPROM is free
    return 0;
}

int EEPROMManipulator::writeDataBlock(char* vectorChar, int size, int pos){
    int posPointer = pos;
    for(int i = pos; i < size; i++){
        //if(!simulatedEEPROM->write(vectorChar[i], posPointer++)) return 1;
        simulatedEEPROM->write(vectorChar[i], posPointer++);
        memControl++;
    }//end of for
    return 0;
}

int EEPROMManipulator::writeData(char letter, int pos){
    if(!simulatedEEPROM->write(letter, pos)) return 1;
    memControl++;
    return 0;
}

char EEPROMManipulator::readData(int pos){
    return simulatedEEPROM->read(pos);
}

char* EEPROMManipulator::readDataBlock(int pos, int end){
    char* result = new char[end-pos];
    int memPointer = pos;
    for(int i = 0; i <= end - pos; i++){
        result[i] = simulatedEEPROM->read(memPointer++);
    }
    return result;
}
*/
