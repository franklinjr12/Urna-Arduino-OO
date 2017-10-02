#include <Urn.h>
#include <EEPROM.h>


//instances of objects of memory
Memory*           arduinoMemory;
MemoryFactory*    memoryCreator;
MemoryControler*  arduinoMemoryControler;
UrnSetup*         urnConfiguration;
UrnElection*      unrElection;
//====================================================================

char* candidatesList;
int i = 0;
String cand = "Franklin";

void setup()
{
    Serial.begin(9600);
  
    //making the instance of the memory
    //MemoryFactory* memoryCreator = new MemoryFactory;
    memoryCreator = new MemoryFactory;
    arduinoMemory = memoryCreator->createMemoryArduino(40);
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


    //nomes de candidatos para testes
    String nomes[] = {"Franklin","Airton","Lucas","Joao"};
    //====================================================================

    
    //add candidates here
    //urnConfiguration->newElection();
    //urnConfiguration->addCandidate("nome", nome.length());
    //delete urnConfiguration;
    //====================================================================

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

  candidatesList = unrElection->listCandidates();
  if(candidatesList == 0)  Serial.println("Erro ao pegar candidatos");
  else                     Serial.println("Lista de candidatos ok");
  
  while(candidatesList[i] != '\0')
  {
    Serial.print(candidatesList[i++]);
  }
  i = 0;

  if(!unrElection->vote(cand.c_str(), cand.length())) Serial.println("\nVoto realizado com sucesso");
  else                                               Serial.println("\nNao foi possivel realizar o voto");
  
  Serial.println("\nTeste");
  delay(1000);
}

