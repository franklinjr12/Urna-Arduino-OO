#include <iostream>
#include <string>
#include "memory.h"
#include "MemoryControler.h"
#include "Urn.h"
//#include "eeprommanipulator.h"
//#include <string.h>
//#include "../headers/
using namespace std;

// Implementando o cabeçalho memoryControler - OK
// implementando o cabeçalho urn
// parei em adicionar um cadidato

int main(){

    MemoryFactory mf;
    Memory* m1 = mf.createMemory();
    MemoryControler* mc1 = new MemoryControlerTest;

    UrnElection* ue1 = new UrnElection(mc1, m1);
    UrnSetup* us1 = new UrnSetup(mc1, m1);
    us1->newElection();
    us1->addCandidate("adnaldo",7);
    us1->addCandidate("oie", 3);


   char* a = ue1->listCandidates();
    //for(int i = 0; i < 10; i++)
    //    cout << a[i];
    //cout << endl;

    return 0;
}
