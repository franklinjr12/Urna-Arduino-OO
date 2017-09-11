/* Desenvolvido por Lucas Oliveira */
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* CLASSE INTERFACE GRAFICA */
class InterfaceGrafica{
  public:
    void criaMensagem(int linha, int coluna, int delay, char* mensagem);
  
};

//metodo criar mensagem
void InterfaceGrafica::criaMensagem(int linha, int coluna, int espera, char* mensagem){
	int tamanhoReal = strlen(mensagem);
  	//verifica se a mensagem passada tem menos do que 16 caracteres
  	//se tiver menos que 16 ele vai printar normalmente
	if(strlen(mensagem) < 16){

	  //Limpa a tela
	  lcd.clear();
	  //Posiciona o cursor na coluna, linha;
	  lcd.setCursor(coluna, linha);
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
//fim metodo criar mensagem

/* FIM CLASSE INTERFACE GRAFICA */


void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}

void loop()
{
  InterfaceGrafica p1;//instancia um ponteiro para a classe interfaceGrafica
  char msg1[] = "Lucas de Oliveira Pereira";//cria uma variavel com a mensagem
  p1.criaMensagem(0,0,1000,msg1);//instancia o metodo criarmensagem

}
