//TRATAMENTO DE DADOS

#include <iostream>
#include <string>
#include "Urn.h"
#include "interfaceGrafica.h"
#include "keyBoard"



using namespace std;

class CORE {
public:
	void memoryCore();
	void boardCore();
	void lcdCore();
};


void CORE::memoryCore(){
    char nomeSize1=99;

    char vote[nomeSize1]="Candidator1";

    if(!UrnElection::vote(&vote[0], nomeSize1)){
        //LCD PRINT OK (VOTO DEU CERTO)
        //IMPLEMENTAR PARA O LCD IMPRIMIR
    }else{
        // LCD PRINT ERRO (O VOTO NÃO DEU CERTO)
    }

    char listCandidatos[]= UrnElection::listCandidates();
//    FAZER O LCD IMPRIMIR A LISTA DE  CANDIDATOS
}

void CORE::lcdCore(){


}

void CORE::boardCore(){



}
