#ifndef CORE_H
#define CORE_H

#include <LiquidCrystal.h>
#include "TextInterfaceRaw.h"
#include "Urn.h"
#include "UrnKeyboard.h"

class Core
{
  private:

    UrnSetup* configuracao;
    UrnElection* eleicao;
    UrnKeyboard* teclado;
    TextInterfaceRaw* tela;

    char opcao;
    Candidate* listaCandidatos;
    int numCandidatos;

  public:

      Core(UrnSetup* uSetup, UrnElection* election, UrnKeyboard* keyboard, TextInterfaceRaw* lcd);
      void showMenu();
      void showCandidates();
      void vote();
      void printError();
      char getOpcao(){return this->opcao;}

};

Core::Core(UrnSetup* uSetup, UrnElection* election, UrnKeyboard* keyboard, TextInterfaceRaw* lcd)
{
  this->configuracao = uSetup;
  this->eleicao = election;
  this->teclado = keyboard;
  this->tela = lcd;

  this->opcao = '\0';
  this->listaCandidatos = election->listCandidates();
  delay(20);
  this->numCandidatos = election->getNumberCandidates();
  delay(20);
  this->tela->clearScreen();
  delay(20);
  this->tela->showText("Inicializando a urna");
  delay(500);
  this->tela->showText("Inicializando a urna .");
  delay(500);
  this->tela->showText("Inicializando a urna . .");
  delay(500);
  this->tela->showText("Inicializando a urna . . .");
  delay(200);
}

void Core::printError()
{

    this->tela->clearScreen();
    this->tela->showText("Erro");
    this->opcao = '\0';
    delay(1000);
}

void Core::showMenu()
{
  this->tela->clearScreen();
  this->tela->showText("1 - Candidatos  2 - Votar");
  while(this->opcao == '\0')
    this->opcao = teclado->takeDigit();
}

void Core::showCandidates()
{

  this->tela->clearScreen();
  String mensagem;
  for(int i = 0; i < this->numCandidatos; i++)
  {
    mensagem = this->listaCandidatos[i].getName();
    mensagem += " ";
    mensagem += this->listaCandidatos[i].getVotes();

    this->tela->showText(mensagem.c_str());
    delay(1500);
    this->tela->clearScreen();

    mensagem = "";
  }

  this->opcao = '\0';
}


void Core::vote()
{

  String vote = "";
  int candidatePosition;
  char digit = '\0';

  this->tela->clearScreen();
  tela->showText("Digite seu voto: ");
  char mensagem[2]; mensagem[1] = '\0';
  while(digit != '*')
  {
    digit = this->teclado->takeDigit();
    if(digit == '\0'){}
    else
    {
      mensagem[0] = digit;
      this->tela->showText(&mensagem[0]);
      vote += digit;
    }
  }

  candidatePosition = atoi(vote.c_str());

  if(candidatePosition > this->numCandidatos)
  {
    this->tela->clearScreen();
    this->tela->showText("Candidato inexistente");
    delay(1500);
  }
  else
  {
    if(!this->eleicao->vote(listaCandidatos[candidatePosition]))
    {
      this->tela->clearScreen();
      this->tela->showText("Voto realizado!");
      delay(1500);
    }
    else
    {
      this->tela->clearScreen();
      this->tela->showText("Ocorreu um erro na votacao :(");
      delay(1500);
    }
  }

  this->listaCandidatos = this->eleicao->listCandidates();
  this->opcao = '\0';
}
//====================================================================================================================================
//====================================================================================================================================

#endif // CORE_H
