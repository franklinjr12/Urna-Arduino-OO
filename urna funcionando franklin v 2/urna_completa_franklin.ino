#include <Core.h>


//====================================================================================================================================
//====================================================================================================================================
//INSTANCIANDO TELA
LiquidCrystal l(0,1,2,3,4,5);
TextInterfaceRaw* telaUrna;
//====================================================================================================================================
//====================================================================================================================================

//====================================================================================================================================
//====================================================================================================================================
//INSTANCIANDO KEYPAD
const byte rows = 4; //four rows
const byte cols = 3; //three columns
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rows] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[cols] = {10, 11, 12}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

KeyboardController* controladorTeclado = new KeyboardControllerArduino;
UrnKeyboard* tecladoUrna = new UrnKeyboard;
//====================================================================================================================================
//====================================================================================================================================

//====================================================================================================================================
//====================================================================================================================================
//INSTANCIANDO MEMORIA
Memory*           arduinoMemory;
MemoryFactory*    memoryCreator;
MemoryControler*  arduinoMemoryControler;
UrnSetup*         urnConfiguration;
UrnElection*      unrElection;
//====================================================================================================================================
//====================================================================================================================================

//====================================================================================================================================
//====================================================================================================================================
//INSTANCIANDO CORE
Core* nucleo;
//====================================================================================================================================
//====================================================================================================================================

void setup() {

  
  //fazendo link de objetos

  //TELA
  l.begin(16,2);
  telaUrna = new TextInterfaceRaw(&l);
  //====================================================================================================================================
  
  //TECLADO
  controladorTeclado->assign(&keypad);
  tecladoUrna->assign(controladorTeclado);
  //====================================================================================================================================
  
  //MEMORIA
    memoryCreator = new MemoryFactory;
    arduinoMemory = memoryCreator->createMemoryArduino(100);
    delete memoryCreator;
    //====================================================================

    //making the instance of the memoryControler
    //MemoryControler* arduinoMemoryControler = new MemoryControlerArduino;
    arduinoMemoryControler = new MemoryControlerArduino;
    arduinoMemoryControler->assign(arduinoMemory);
    //====================================================================


    //making the instance of the Setup object
    //UrnSetup* urnConfiguration = new UrnSetup(arduinoMemoryControler, arduinoMemory);
    urnConfiguration = new UrnSetup(arduinoMemoryControler, arduinoMemory);
    //====================================================================

    //making the instance of Election object
    //UrnElection* unrElection = new UrnElection(arduinoMemoryControler, arduinoMemory);
    unrElection = new UrnElection(arduinoMemoryControler, arduinoMemory);
    //====================================================================

    /*
    Candidate* cand = (Candidate*) malloc(3 * sizeof(Candidate));
    //candidatos para votar

    
    cand[0].setName("joao");
    cand[0].setVote(0);
    delay(20);
    cand[1].setName("roberto");
    cand[1].setVote(0);
    delay(20);
    cand[2].setName("yan");
    cand[2].setVote(0);
    delay(20);
    //add candidates here
    urnConfiguration->newElection();
    urnConfiguration->addCandidate(cand[0]);
    delay(20);
    urnConfiguration->addCandidate(cand[1]);
    delay(20);    
    urnConfiguration->addCandidate(cand[2]);
    delay(20);
    //delete urnConfiguration;
    //*/
    
    urnConfiguration->newElection();
    Candidate c;
    c.setName("Michel Corci");
    urnConfiguration->addCandidate(c);
    c.setName("Lucio Geronimo");
    urnConfiguration->addCandidate(c);
    c.setName("Aline de Colculo");
    urnConfiguration->addCandidate(c);
    
    //====================================================================
    //====================================================================================================================================

    //CORE
    nucleo = new Core(urnConfiguration, unrElection, tecladoUrna, telaUrna); 

}

void loop() {
  // put your main code here, to run repeatedly:


  //teste para ver a memoria EEPROM
  /*
  l.clear();  
  for(int i = 0; i < 16; i++)
  {
    l.print((char)EEPROM[i]);
    //delay(1000);
  }
  l.setCursor(0,1);
  for(int i = 16; i < 32; i++)
  {
    l.print((char)EEPROM[i]);
    //delay(1000);
  }
  delay(5000);
  //*/
  /*
  char* ls = unrElection->listCandidates();

  
  l.clear();
  //l.print(ls);
  //delay(1500);
  l.clear();
  l.print(unrElection->getNumberCandidates());
  delay(1500);
  */
/*
  Candidate* list = unrElection->listCandidates();
  String s = list[0].getName();
  char* a = &s[0];
  l.clear();
  telaUrna->showText(a);
  delay(1000);
*/
  
  nucleo->showMenu();

  switch(nucleo->getOpcao())
  {
    case '1':
            nucleo->showCandidates();
            break;
    
    case '2':
            nucleo->vote();
            break;          
    
    default:
            nucleo->printError();
            break;       
  }

}
