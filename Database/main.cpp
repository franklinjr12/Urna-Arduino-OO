#include <iostream>
#include <string>
#include "eeprom.h"
//#include "../headers/
using namespace std;



int main(){

    EEPROMFactory ef1;
    EEPROM* ep1 = ef1.createEEPROM(10);
    string name = "franklin";

    if(!ep1->write('a',11)) cout << "Write success\n";
    else cout << "Failure on write data\n";


    return 0;
}
