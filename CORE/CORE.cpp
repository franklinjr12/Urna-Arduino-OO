//TRATAMENTO DE DADOS

#include <iostream>
#include <string>
#include "Urn.h"
#include "interfaceGrafica.h"

//#include "keyBoard"
//FALTA A IMPLEMENTAÇÃO DO KEYBOARD


using namespace std;

class CORE {
public:
	void memoryCore();
	void boardCore();
	void lcdCore();
};
//==============================================================================
//EXIBE MENSAGEM DE BEM VINDO
void CORE::lcdCore(){
    int espera=1000;
    char mensagemI[]="Bem Vindo a Urna OO";
    InterfaceGrafica::mostrarMensagem(????, ????, espera, &mensagemI[0]);
}
//==============================================================================


//==============================================================================
//IMPLEMENTCAO PARA O TECLADO
void CORE::boardCore(){

//CODE

}
//==============================================================================


void CORE::memoryCore(){
    char nomeSize1=99;

    int espera=1000;

    char vote[nomeSize1]="Candidator1";

//==============================================================================
//        VERIFICA SE O VOTO DE CERTO OU NAO!!!
    if(!UrnElection::vote(&vote[0], nomeSize1)){
//        LCD PRINT OK (VOTO DEU CERTO)
//        IMPLEMENTAR PARA O LCD IMPRIMIR
        char msg1[]="SUCCESS!!!"
        InterfaceGrafica::mostrarMensagem(????, ????, espera, &msg1[0]);
//        ESTOU COM DUVIDAS QUANTO A "LINHAS" E "COLUNA" QUE ESTA FUNCAO RECEBE
    }else{
//         LCD PRINT ERRO (O VOTO NAO DEU CERTO)
        char msg2[]="ERROR!!!"
        InterfaceGrafica::mostrarMensagem(????, ????, espera, &msg2[0]);
//         ESTOU COM DUVIDAS QUANTO A "LINHAS" E "COLUNA" QUE ESTA FUNÇÃO RECEBE
    }
//==============================================================================


//==============================================================================
    char listCandidatos[]= UrnElection::listCandidates();
//    FAZER O LCD IMPRIMIR A LISTA DE  CANDIDATOS
    InterfaceGrafica::mostrarMensagem(????, ????, espera, &listCandidatos[0]);
//==============================================================================
}

