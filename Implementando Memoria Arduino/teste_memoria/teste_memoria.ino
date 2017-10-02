#include <Urn.h>
#include <EEPROM.h>


//instances of objects of memory
Memory*           arduinoMemory;
MemoryFactory*    memoryCreator;
MemoryControler*  arduinoMemoryControler;
UrnSetup*         urnConfiguration;
UrnElection*      unrElection;
//====================================================================

//auxiliars variables
char* candidatesList; //variable to store candidates and its votes
int i = 0;  //for counting loops
String cand = "Franklin"; //candidate to be voted
//====================================================================


void setup()
{
    Serial.begin(9600); //for displaing info on IDE screen
  
    //making the instance of the memory
    memoryCreator = new MemoryFactory;
    arduinoMemory = memoryCreator->createMemoryArduino(40);
    delete memoryCreator;
    //====================================================================

    //making the instance of the memoryControler
    arduinoMemoryControler = new MemoryControlerArduino;
    arduinoMemoryControler->assign(arduinoMemory);
    //====================================================================


    //making the instance of the Setup object
    urnConfiguration = new UrnSetup(arduinoMemoryControler, arduinoMemory);
    //====================================================================

    //making the instance of Election object
    unrElection = new UrnElection(arduinoMemoryControler, arduinoMemory);
    //====================================================================


    //candidates names for tests
    String nomes[] = {"Franklin","Airton","Lucas","Joao"};
    //====================================================================

    
    //add candidates here
    //urnConfiguration->newElection();
    //urnConfiguration->addCandidate("nome", nome.length());
    //delete urnConfiguration;
    //====================================================================


    //part of the code responsable for cleaning the memory and adding the candidates
    //obs: need to be executed only once
   /*
    if(!urnConfiguration->newElection()) Serial.println("Memoria limpa");
    else  Serial.println("Nao foi possivel limpar a memoria");
    
    for(int i = 0; i < 4; i++)
      if(!urnConfiguration->addCandidate(nomes[i].c_str(), nomes[i].length()))
      {
        Serial.println("candidato ");
        Serial.println(nomes[i]);
        Serial.println(" adicionado com sucesso");
      }
      else Serial.println("Nao foi possivel adicionar o candidato\n");
    */
    delete urnConfiguration;
}

void loop()
{ 

  //putting the string of candidates and its votes into a variable
  candidatesList = unrElection->listCandidates();
  if(candidatesList == 0)  Serial.println("Erro ao pegar candidatos");
  else                     Serial.println("Lista de candidatos ok");
 //====================================================================


  //printing the candidates in the pc screen with serial of arduino IDE
  while(candidatesList[i] != '\0')
  {
    Serial.print(candidatesList[i++]);
  }
  i = 0;
  //====================================================================

  //making a vote into one candidate just to test
  if(!unrElection->vote(cand.c_str(), cand.length())) Serial.println("\nVoto realizado com sucesso");
  else                                               Serial.println("\nNao foi possivel realizar o voto");
  //====================================================================
  
  delay(1000);
}

