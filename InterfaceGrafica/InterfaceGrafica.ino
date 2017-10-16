/* Desenvolvido por Lucas Oliveira */
#include <LiquidCrystal.h>
#include <InterfaceGrafica.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}

void loop()
{
  InterfaceGrafica p1;//instancia um ponteiro para a classe interfaceGrafica
  char msg1[] = "Lucas de Oliveira Pereira";//cria uma variavel com a mensagem
  p1.mensagemDisplay(msg1);//instancia o metodo criarmensagem
}
