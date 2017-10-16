#include <Keypad.h>

//recebe o numero de colunas
//as teclas(pode só devolver um numero que represente a coluna)
//as portas(a primeira porta é a da linha e as outras são de colunas)
//e faz uma linha do teclado
class Keyreader
{
private:
  static const byte ROW = 1;
  static byte COLS;
  char &keys;
  byte rowPin;
  byte &colPins;
  Keypad kpd;
public:
  Keyreader();
  void getN(byte nCols);
  void getC(char cols[]);
  void getRD(byte door);
  void getCD(byte doors[]);
  void start();
  char fish();
};

//Keyreader::Keyreader()
//{
//  this->COLS = 0;
//  Serial.begin(9600);
//}

void Keyreader::getN(byte nCols)
{
  this->COLS = nCols;
}

void Keyreader::getC(char cols[])
{
  for (int i = 0; i < Keyreader::COLS; i++)
  {
    this->keys = &cols;
  }
}

void Keyreader::getRD(byte door)
{
  this->rowPin = door;
}

void Keyreader::getCD(byte doors[])
{
  for (int i = 0; i < Keyreader::COLS; i++)
  {
    this->colPins = &doors;
  }
}

void Keyreader::start()
{
  this-> kpd = Keypad(makeKeymap(keys), rowPin, colPins, ROW, COLS);
}

char Keyreader::fish()
{
  char key = kpd.getKey();
  if (key)  // Checa se um botão foi pressionado.
  {
    return key;
  }
}

Keyreader* k1;
void setup() {
  k1 = new Keyreader;
  Serial.begin(9600);
}

void loop() {
  char k[3] = { '1','2','3' };
  byte d[3] = { 4, 3, 2 };
  char key;
  k1->getN(3);
  k1->getC(k);
  k1->getRD(8);
  k1->getCD(d);
  k1->start();
  key = k1->fish();
}
