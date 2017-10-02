#ifndef MEMORYCONTROLER_H
#define MEMORYCONTROLER_H

#include "memory.h"
#include "Arduino.h"
#include <EEPROM.h>


class MemoryControler{
    // class responsable to manipulate the memory
    // abstract
    public:
        //
        // writes the letter to the respective adress of the memory passed as position
        virtual int write(char letter, int position){return -1;}

        // returns the char that is in the adress position of the memory
        virtual char read(int position){return '!';}

        // assign a memory for the controler
        virtual int assign(Memory* mem){return -1;}


        MemoryControler(){memoryAssigned = 0;}

    protected:
        Memory* memoryAssigned;
};

class MemoryControlerTest : public MemoryControler{
    // class used for test the program in the console
    public:
        int write(char letter, int position);
        char read(int position);
        int assign(Memory* mem);

};

class MemoryControlerArduino : public MemoryControler{
    public:
        int write(char letter, int position);
        char read(int position);
        int assign(Memory* mem);
};

#endif // MEMORYCONTROLER_H
