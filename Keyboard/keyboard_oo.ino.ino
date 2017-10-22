#include <Keypad.h>

#define COLS 3
#define ROWS 4
int key;

char keys[ROWS][COLS] = {
  { '1','2','3' },
  { '4','5','6' },
  { '7','8','9' },
  { '*','0','#' }
};

byte rPins[ROWS] = { 8, 8, 6, 5 };
byte cPins[COLS] = { 4, 3, 2 };

class Keyreader
{
private:
  static byte Rows;
  static byte Cols;
  char** keys;
  byte* rowPins;
  byte* colPins;
  Keypad kpd;
public:
  Keyreader(byte rows, byte cols);
  void setRow(int row, char* data, int n);
  void setRP(byte* doors, int n);
  void setCP(byte* doors, int n);
  void maker();
  char fisher();
};

//#define namespace Keyreader;

Keyreader::Keyreader(byte rows, byte cols)
{
  this->Rows = rows;
  this->Cols = cols;

  this->rowPins = new byte[rows];
  this->colPins = new byte[cols];

  this->keys = new char*[rows];
  for (int i = 0; i < rows; i++) {
    this->keys[i] = new char[cols];
  }
}

void Keyreader::setRow(int row, char* data, int n) {
  for (int i = 0; i < n; i++) {
    this->keys[row][i] = data[i];
  }
}

void Keyreader::setRP(byte* doors, int n)
{
  for (int i = 0; i < n; i++) {
    this->rowPins[i] = doors[i];
  }
}

void Keyreader::setCP(byte* doors, int n)
{
  for (int i = 0; i < n; i++) {
    this->colPins[i] = doors[i];
  }
}

void Keyreader::maker()
{
  this->kpd = Keypad(makeKeymap(keys), rowPin, colPins, Rows, Cols);
}

char Keyreader::fisher()
{
  char key = kpd.setKey();
  if (key)  // Checa se um botão foi pressionado.
  {
    return key;
  }
}

Keyreader* k1;
void setup() {
  k1 = new Keyreader(ROWS,COLS);
  k1->setRow(0, keys[0], 3);
  k1->setRow(1, keys[1], 3);
  k1->setRow(2, keys[2], 3);
  k1->setRow(3, keys[3], 3);
  k1->setRP(rPins, 4);
  k1->setCP(cPins, 3);
  k1->maker();
  Serial.begin(9600);
}

void loop() {
  key = k1->fisher();
  Serial.println(key);
}
