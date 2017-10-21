/* Desenvolvido por Lucas Oliveira */
#include <InterfaceGrafica.h>
DisplayLCD16x2 *p = new DisplayLCD16x2(12, 11, 5, 4, 3, 2); //instancio a classe Display LCD 16x2
LiquidCrystal *tela = p->getLCD();//crio um ponteiro e aponto para o lcd da classe interface grafica
/* preciso apontar para o mesmo lcd pelo fato do tratamento das mensagem acontecerem externamente */ 

void setup()
{
  //Define o número de colunas e linhas do LCD
  tela->begin(16, 2);

}

void loop()
{
  char msg1[] = "Lucas de Oliveira Pereira";//cria uma variavel com a mensagem
<<<<<<< HEAD
  p->mensagemDisplay(msg1);//instancia o metodo criarmensagem
}
=======
  p1.mensagemDisplay(msg1);//instancia o metodo criarmensagem
}
>>>>>>> 452c709e995cdae47da00a11351a8d7c3276a954
