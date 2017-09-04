#include <iostream>
#include <string>
#include "eeprom.h"
#include "eeprommanipulator.h"
#include <string.h>
//#include "../headers/
using namespace std;



int main(){

    EEPROMFactory ef1;
    EEPROM* ep1 = ef1.createEEPROM(10);
    int size = 5;
    char name[size];
    EEPROMManipulator em1(ep1);

    em1.eraseAllData();

    cout << em1.readDataBlock(0,9) << endl;


    strcpy(name,"frenk");

    em1.writeDataBlock(&name[0], size, 0);


    char* s = em1.readDataBlock(0,9);

    cout << s << endl;

    return 0;
}
