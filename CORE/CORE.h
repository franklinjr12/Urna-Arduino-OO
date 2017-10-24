/*DESENVOLVIDO POR AIRTON RAMOS*/

#ifndef CORE_H
#define CORE_H

#include "Urn.h"
#include "UrnKeyboard.h"
#include "InterfaceGrafica.h"
#include "EEPROM.h"
#include "LiquidCrystal.h"

class CORE {
private:
    Candidate* c1;
    UrnSetup* addCandidate;
    UrnKeyboard* tec;
    Candidate cd1;
    Candidate cd2;
public:
    void EscolhaCandidatosEvotar();
    void iniciarUrna();
    void votar();
    void listar();
    Candidate getCd1();
    void setCd1(Candidate nome);
    Candidate getCd2();
    void setCd2(Candidate nome2);
    CORE(UrnElection* nEle, Candidate* cand, UrnSetup* addCan, UrnKeyboard* tc);
};

#endif // CORE_H
