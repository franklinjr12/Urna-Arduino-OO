#include "memory.h"
#include "MemoryControler.h"
#include "Urn.h"



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


    //add candidates here
    //urnConfiguration->addCandidate("name", name.size());
    //====================================================================


}

void loop()
{

}
