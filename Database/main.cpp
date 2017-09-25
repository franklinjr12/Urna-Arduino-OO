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
// list candidates - OK
// vote - OK
// implementar no arduino

int main(){

    //instanciating objects
    MemoryFactory mf;
    Memory* m1 = mf.createMemory();
    MemoryControler* mc1 = new MemoryControlerTest;
    UrnElection* ue1 = new UrnElection(mc1, m1);
    UrnSetup* us1 = new UrnSetup(mc1, m1);
    //===============================


    //seting up the memory
    us1->newElection();
    //===============================

    //adding candidates
    string cand1 = "Airton";
    us1->addCandidate(&cand1[0], cand1.size());
    cand1 = "Joao";
    us1->addCandidate(&cand1[0], cand1.size());
    cand1 = "Frank";
    us1->addCandidate(&cand1[0], cand1.size());
    //===============================

    //listing candidates in the memory
    char* s = ue1->listCandidates();
    if(s) cout << s << endl;
    else cout << "erro";
    //====================================

    //vote
    for(int i = 1; i <= 11; i++) ue1->vote(&cand1[0], cand1.size());
    if(ue1->vote("Gay", 3)) cout << "Voto realizando com sucesso\n";
    else cout << "Candidato nao existe\n";
    if(ue1->vote("Airton", 6)) cout << "Voto realizando com sucesso\n";
    else cout << "Candidato nao existe\n";

    s = ue1->listCandidates();
    cout << s << endl;
    //===============================================


    return 0;
}
