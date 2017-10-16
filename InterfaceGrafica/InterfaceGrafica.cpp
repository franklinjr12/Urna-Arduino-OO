<<<<<<< HEAD
/* Desenvolvido por Lucas Oliveira */
#include "InterfaceGrafica.h"
#include <cstring>

using namespace std;

//metodo mostrar Mensagem
void InterfaceGrafica::criaMensagem(int linha, int coluna, int espera, char* mensagem){
	int tamanhoReal = strlen(mensagem);
  	//verifica se a mensagem passada tem menos do que 16 caracteres
  	//se tiver menos que 16 ele vai printar normalmente
	if(strlen(mensagem) < 16){

	  //Limpa a tela
	  lcd.clear();
	  //Posiciona o cursor na coluna, linha;
	  lcd.setCursor(0, 0);
	  //Envia o texto entre aspas para o LCD
	  lcd.print(mensagem);
	  //tempo de espera para a mensagem
	  delay(espera);
	  lcd.clear();

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
		lcd.clear();

		lcd.setCursor(0, 0);
		lcd.print(aux1);

		lcd.setCursor(0, 1);
		lcd.print(aux2);

		//tempo de espera para a mensagem
		delay(espera);
		lcd.clear();

	}
	
}
//fim metodo
//metodo mensagemDisplay
void InterfaceGrafica::mensagemDisplay(char *msg){
  //chama o metodo criar mensagem
  criaMensagem(0,0,ESPERA,msg);
}