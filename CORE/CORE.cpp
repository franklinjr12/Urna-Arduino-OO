/*DESENVOLVIDO POR AIRTON RAMOS*/

#include "CORE.h"

void CORE::iniciarUrna(){

  KeyboardController* kbc;
  UrnKeyboard* teclado;
  DisplayLCD16x2 *p = new DisplayLCD16x2(12, 11, 5, 4, 3, 2); //instancio a classe Display LCD 16x2
  char msg1[] = "Bem Vindo a Urna OO"; // MENSAGEM DE INICIO DA URNA
  p->mensagemDisplaySemEspera(msg1);
  delay(5000);

  //==================================================================================================

  //CRIAR CANDIDATO
  Candidate novoCand;
  novoCand.setName((char *)"Bolsonaro");
  novoCand.setVote(0);

  setCd1(novoCand);

  Candidate novoCand2;
  novoCand2.setName((char *)"Lula");
  novoCand2.setVote(0);

  setCd2(novoCand2);
  //==================================================================================================
  //ADICIONAR UM CANDIDATO NA MEMORIA
  UrnSetup* addCand;
  addCand->addCandidate(novoCand);// VER SE ESTA CERTO

  addCand->addCandidate(novoCand2);

  //==================================================================================================
  UrnElection* novaEleicao;
  //==================================================================================================

  //NOVA ELEICAO

  char msg[] = "DIGITE 1-> LISTA CANDIDATOS";
  p->mensagemDisplaySemEspera(msg);
  delay(2000);
  //IMPLEMENTAR PARA RECEBER O NUMERO DO KEYBOARD
  //==================================================================================================
  char msg0[] = "DIGITE 2-> VOTAR";
  p->mensagemDisplaySemEspera(msg0);
  delay(2000);

  //==================================================================================================

  int key=-1;
  //  IMPLEMENTAR PATA KEYBOAD MANDAR UM DIGITE E COLOCADO NA VARIAVEL "KEY"
  key=teclado->takeDigit();
  //Candidate listC;
  CORE* lCandidatos;
    switch(key){

      case 1:lCandidatos->listar(); break;

      case 2:lCandidatos->votar(); break;
  }
}

void CORE::votar(){
    KeyboardController* kbc1;
    UrnKeyboard* teclado1;
    int kay=0;
    kay=teclado1->takeDigit();

    //==================================================================================================
    DisplayLCD16x2 *p5 = new DisplayLCD16x2(12, 11, 5, 4, 3, 2); //instancio a classe Display LCD 16x2
    //==================================================================================================

    UrnElection* esc;
    switch(kay){

        case 1: esc->vote(getCd1());
        case 2: esc->vote(getCd2());
    }
    char msg4[] = "VOTO REALIZADO COM SUCESSO!!!";
    p5->mensagemDisplaySemEspera(msg4);
    delay(2000);
}
void CORE::listar(){

   DisplayLCD16x2 *p2 = new DisplayLCD16x2(12, 11, 5, 4, 3, 2); //instancio a classe Display LCD 16x2
   UrnElection* novaEleicao;
   Candidate* listCandidatos = novaEleicao->listCandidates();//LISTA OS CANDIDATOS NO DISPLAY

   p2->mensagemDisplaySemEspera(listCandidatos->getName());
   delay(5000);
//  VERIFICAR PROVAVEIS ERROS DETS FUNÇÃO
}
//gets e sets

void CORE::setCd1(Candidate nome){
    this->cd1 = nome;
}
void CORE::setCd2(Candidate nome2){
    this->cd2 = nome2;
}

Candidate CORE::getCd1(){
    return this->cd1;
}
Candidate CORE::getCd2(){
    return this->cd2;
}
