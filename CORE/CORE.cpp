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

    int espera=1000;

    char vote[nomeSize1]="Candidator1";

//        VERIFICA SE O VOTO DE CERTO OU NÃO!!!
    if(!UrnElection::vote(&vote[0], nomeSize1)){
//        LCD PRINT OK (VOTO DEU CERTO)
//        IMPLEMENTAR PARA O LCD IMPRIMIR
        char msg1[]="SUCCESS!!!"
        InterfaceGrafica::mostrarMensagem(????, ????, espera, &msg1[0]);
//        ESTOU COM DUVIDAS QUANTO A "LINHAS" E "COLUNA" QUE ESTA FUNÇÃO RECEBE
    }else{
//         LCD PRINT ERRO (O VOTO NÃO DEU CERTO)
        char msg2[]="ERROR!!!"
        InterfaceGrafica::mostrarMensagem(????, ????, espera, &msg2[0]);
//         ESTOU COM DUVIDAS QUANTO A "LINHAS" E "COLUNA" QUE ESTA FUNÇÃO RECEBE
    }

    char listCandidatos[]= UrnElection::listCandidates();
//    FAZER O LCD IMPRIMIR A LISTA DE  CANDIDATOS
    InterfaceGrafica::mostrarMensagem(????, ????, espera, &listCandidatos[0]);
}

void CORE::lcdCore(){


}

void CORE::boardCore(){



}
