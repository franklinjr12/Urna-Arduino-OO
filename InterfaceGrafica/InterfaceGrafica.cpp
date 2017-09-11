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
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna, linha;
  lcd.setCursor(coluna, linha);
  //Envia o texto entre aspas para o LCD
  lcd.print(mensagem);
  //tempo de espera para a mensagem
  delay(espera);
  lcd.clear();
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
  InterfaceGrafica p1,p2;
  char msg[] = "Ola, seja bem-vindo(a)";
  char msg2[] = "Digite a sua Acao:";
  p1.criaMensagem(0,0,1000,msg);
  p2.criaMensagem(0,0,1000,msg2);
}
