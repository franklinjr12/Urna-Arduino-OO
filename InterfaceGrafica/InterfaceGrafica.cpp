/* Desenvolvido por Lucas Oliveira */
#include "InterfaceGrafica.h"
#include <cstring>
#define ESPERA 2000;

//contador de caracteres
int strlen(char *str){
    int total=0;

    while( str[total] != '\0') 
    	total++;

    return total;
}
//metodo mostrar Mensagem
void InterfaceGrafica::criaMensagem(int linha, int coluna, int espera, char* mensagem){
	int tamanhoReal = strlen(mensagem);
  	//verifica se a mensagem passada tem menos do que 16 caracteres
  	//se tiver menos que 16 ele vai printar normalmente
	if(tamanhoReal < 16){

	  //Limpa a tela
	  this->lcd->clear();
	  //Posiciona o cursor na coluna, linha;
	  this->lcd->setCursor(0, 0);
	  //Envia o texto entre aspas para o tela
	  this->lcd->print(mensagem);

	  //tempo de espera para a mensagem
		if(espera != 0){
			delay(espera);
			this->lcd->clear();
		}

	//caso a mensagem seja maior que 16 caracteres sera quebrada para ser printada em duas linhas
	//sera criada uma variavel auxiliar que sera passado os caracteres que faltaram para imprimir
	}else{

		int tamanhoAux = tamanhoReal - 16;//define o tamanho do novo vetor sendo o tamanho dos caracteres restantes
		char aux1[16], aux2[tamanhoAux];

		//aux 1
		for(int i = 0; i < 16; i++){
			//copia os caracteres restantes para o novo vetor
			aux1[i] = mensagem[i];
		}

		//aux2
		for(int i = 0, j = 16; i < tamanhoAux, j <= tamanhoReal; i++, j++){
			//copia os caracteres restantes ara o novo vetor
			aux2[i] = mensagem[j];
		}

		//Limpa a tela
		this->lcd->clear();

		this->lcd->setCursor(0, 0);
		this->lcd->print(aux1);

		this->lcd->setCursor(0, 1);
		this->lcd->print(aux2);

		//tempo de espera para a mensagem
		if(espera != 0){
			delay(espera);
			this->lcd->clear();
		}

	}
	
}
//fim metodo

//metodo mensagemDisplay
void InterfaceGrafica::mensagemDisplay(char *msg){
  //chama o metodo criar mensagem
  criaMensagem(0,0,2000,msg);
}

//metodo mensagemDisplaySemEspera
void InterfaceGrafica::mensagemDisplaySemEspera(char *msg){
  //chama o metodo criar mensagem
  criaMensagem(0,0,0,msg);
}

//setLCD
void InterfaceGrafica::setLCD(int *p1, int *p2, int *p3, int *p4, int *p5, int *p6){

    	LiquidCrystal lcd(p1, p2, p3, p4, p5, p6);
    	this->lcd = &lcd;
}
//getLCD
LiquidCrystal* InterfaceGrafica::getLCD(){
	return this->lcd;
}
