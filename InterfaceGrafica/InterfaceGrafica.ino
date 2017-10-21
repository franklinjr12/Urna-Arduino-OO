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
  /* COMO UTILIZAR A CLASSE */
  //1º crie uma varia do tipo char com o conteudo da mensagem;
  char msg1[] = "Lucas de Oliveira Pereira";//cria uma variavel com a mensagem
  //2º aponte o ponteiro para o metodo mensagemDisplay passando a variavel da mensagem criada
  //o mensagemDisplay ja contem um tempo embutido, o mensagemDisplaySemEspera voce coloca o delay apos a chamada do metodo
  p->mensagemDisplay(msg1);
  p->mensagemDisplaySemEspera(msg1);
  delay(2000);
}
