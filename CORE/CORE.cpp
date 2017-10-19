#include "CORE.h"

//TRATAMENTO DE DADOS

#include <iostream>
#include <string>
#include "Urn.h"

using namespace std;

//==============================================================================
//EXIBE MENSAGEM DE BEM VINDO

//ESSA PARTE SERÁ IMPLEMENTADA NA IDE DO ARDUINO
//void CORE::lcdCore(){
//    int espera=1000;
//    char mensagemI[]="Bem Vindo a Urna OO";
//    InterfaceGrafica::mostrarMensagem(????, ????, espera, &mensagemI[0]);
//}
//==============================================================================


//==============================================================================
//IMPLEMENTCAO PARA O TECLADO
//void CORE::boardCore(){
//
////CODE
//
//}
//==============================================================================

//OBS: TODA PARTE ENVOLVENDO TECLADO E DISPLAY SERÁ IMPLEMENTADA NO ARDUINO

void CORE::memoryCore(){
    char nomeSize1=99;

    int espera=1000;

    char vote[nomeSize1]="Candidator1";

//==============================================================================
//        VERIFICA SE O VOTO DE CERTO OU NAO!!!
    if(!UrnElection::vote(&vote[0], nomeSize1)){
//        LCD PRINT OK (VOTO DEU CERTO)

        char msg1[]="SUCCESS!!!";

//        InterfaceGrafica::mostrarMensagem(????, ????, espera, &msg1[0]);
//        ESTOU COM DUVIDAS QUANTO A "LINHAS" E "COLUNA" QUE ESTA FUNCAO RECEBE
    }else{
//         LCD PRINT ERRO (O VOTO NAO DEU CERTO)
        char msg2[]="ERROR!!!"
//         InterfaceGrafica::mostrarMensagem(????, ????, espera, &msg2[0]);
//         ESTOU COM DUVIDAS QUANTO A "LINHAS" E "COLUNA" QUE ESTA FUNÇÃO RECEBE
    }
//==============================================================================


//==============================================================================
    char listCandidatos[]= UrnElection::listCandidates();
//    FAZER O LCD IMPRIMIR A LISTA DE  CANDIDATOS
//    InterfaceGrafica::mostrarMensagem(????, ????, espera, &listCandidatos[0]);
//==============================================================================
}

