#include <Urn.h>
#include <EEPROM.h>


    

void setup()
{
    //making the instance of the memory
    MemoryFactory* memoryCreator = new MemoryFactory;
    Memory* arduinoMemory = memoryCreator->createMemoryArduino(1024);
    delete memoryCreator;
    //====================================================================

    //making the instance of the memoryControler
    MemoryControler* arduinoMemoryControler = new MemoryControlerArduino;
    arduinoMemoryControler->assign(arduinoMemory);
    //====================================================================


    //making the instance of the Setup object
    UrnSetup* urnConfiguration = new UrnSetup(arduinoMemoryControler, arduinoMemory);
    //====================================================================

    //making the instance of Election object
    UrnElection* unrElection = new UrnElection(arduinoMemoryControler, arduinoMemory);
    //====================================================================


    //nomes de candidatos para testes
    String nomes[] = {"Franklin","Airton","Lucas","Joao"};
    //====================================================================

    
    //add candidates here
    //urnConfiguration->newElection();
    //urnConfiguration->addCandidate("nome", nome.length());
    //delete urnConfiguration;
    //====================================================================

    urnConfiguration->newElection();
    for(int i = 0; i < 4; i++)
      urnConfiguration->addCandidate(nomes[i].c_str(), nomes[i].length());
    delete urnConfiguration;
}

void loop()
{

}

