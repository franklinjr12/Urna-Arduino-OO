/* Desenvolvido por Lucas Oliveira */
#include <InterfaceGrafica.h>
/* MUDANÇAS */
/* 
- Antes, estavamos utilizando a função propria do Arduino para criar uma váriavel do tipo LiquidCrystal, que era a seguinte:
"LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);" Pelo fato do tratamento da mensagem acontecer separadamente no cód. cpp da classe Interface Grafica, ele necessitava da mesma 
variável LiquidCrystal, por isso, criamos uma tela LiquidCrystal com o " new DisplayLCD16x2(12, 11, 5, 4, 3, 2); " e chamamos ela
em " LiquidCrystal *tela = p->getLCD(); " para ser utilizada internamente aqui no nosso código do arduino.
- A unica diferença agora é que a tela é um ponteiro que aponta p/ a mesma tela LCD utilizada no cód. da classe. Para utilizar os métodos
da Interface gráfica como mensagemDisplay é só utilizar o ponteiro criado para instanciar a classe. que no caso abaixo foi o "p".
- Agora não precisa mais incluir a biblioteca LiquidCrystal no cabeçalho do código, pois ele ja está incluso nos códigos das classes.
*/
/* MUDANÇAS */
DisplayLCD16x2 *p = new DisplayLCD16x2(12, 11, 5, 4, 3, 2); //instancio a classe Display LCD 16x2
LiquidCrystal *tela = p->getLCD();//crio um ponteiro e aponto para o lcd da classe interface grafica
/* preciso apontar para o mesmo lcd pelo fato do tratamento das mensagem acontecerem externamente */ 

void setup()
{
  //Define o número de colunas e linhas do LCD
  //essa parte é padrão o arduino para se poder trabalhar com o LiquidCrystal
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
