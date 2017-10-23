#include <CORE.h>
#include <Arduino.h>

//instances of objects of memory
Memory*           arduinoMemory;
MemoryFactory*    memoryCreator;
MemoryControler*  arduinoMemoryControler;
UrnSetup*         urnConfiguration;
UrnElection*      unrElection;
//====================================================================
CORE* c1;
//==================================================================================================
//ISTANCIANDO OBJETOS DA TELA
DisplayLCD16x2 *p = new DisplayLCD16x2(12, 11, 5, 4, 3, 2); //instancio a classe Display LCD 16x2
LiquidCrystal *tela = p->getLCD();//crio um ponteiro e aponto para o lcd da classe interface grafica

//instanciando objetos do teclado
KeyboardController* kbc;
UrnKeyboard* teclado; 

//==================================================================================================
//criando teclado Keypad
const byte rows = 4; //four rows
const byte cols = 3; //three columns
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[rows] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[cols] = {8, 7, 6}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
//=====================================================================================



 //====================================================================================
void setup() {
  //Define o número de colunas e linhas do LCD
  //essa parte é padrão o arduino para se poder trabalhar com o LiquidCrystal
  tela->begin(16, 2);
  //===================================================================================
  //fazendo a configuracao dos objetos
  kbc = new KeyboardControllerArduino;
  kbc->assign(&keypad);
  
  teclado = new UrnKeyboard;
  teclado->assign(kbc);
 //===================================================================================
}

void loop() {
  // put your main code here, to run repeatedly:
  c1->iniciarUrna();

}
