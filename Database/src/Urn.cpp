#include "Urn.h"

#include <iostream>
using namespace std;

//****************************************************************
//Implementations of UrnSetup

UrnSetup::UrnSetup(MemoryControler* mc, Memory* m){
    memory = m;
    memControler = mc;
    memControler->assign(memory);
}


int UrnSetup::newElection(){
    //error tests
    if(memory == 0) return -1;
    if(memControler == 0) return -1;
    //writing '!' in all memory spaces for it to be "clean"
    for(int i = 0; i < memory->memorySize; i++){
        //cout << i << ' ';
        memControler->write('!', i);
    }

    return 0;
}

//consertar aqui
//adicionar o segundo candidato

int UrnSetup::addCandidate(char* name, int nameSize){
     //error tests
    if(memory == 0) return -1;
    if(memControler == 0) return -1;

    //searching for a free space in the memory
    int pos = 0;    //to mark the position to write the name
    while(pos < memory->memorySize){
        if(memControler->read(pos) == '!' && memControler->read(pos+1) == '!'){ //finding valid position
            pos++;  //to let one '!' behind
            //writing the candidate name
            for(int i = 0; i < nameSize; i++){
                memControler->write(name[i], pos++);
            }
            //writing it's "00" votes
            memControler->write('0', pos++);
            memControler->write('0', pos);
            return 0;
        }// end of if
        pos++;
    }// end of while

    //case there is no free space in the memory
    if(pos >= memory->memorySize) return -1;
    return -1;
}
//***********************************************************************************************************


//***********************************************************************************************************
// Implementations of UrnElection

UrnElection::UrnElection(MemoryControler* mc, Memory* m){
    memory = m;
    memControler = mc;
    memControler->assign(memory);
}

char* UrnElection::listCandidates(){
    // put all candidates and it's votes in a string
    //error tests
    if(memory == 0) return 0;   //null
    if(memControler == 0) return 0; //null

    //counting size for the string
    int listSize = 0;
    int pos = 0;
    while(memControler->read(pos) != '!' && memControler->read(pos+1) != '!'){
        if(memControler->read(pos) != '!'){
            while(memControler->read(pos) != '!'){
                listSize++;
                pos++;
            }
        }
        pos++;
    }// end of while

    //putting the names in a list
    pos = 0;
    int aux = 0;
    char* namesList = new char[listSize+1];

    while(memControler->read(pos) != '!' && memControler->read(pos+1) != '!'){
        if(memControler->read(pos) != '!'){
            while(memControler->read(pos) != '!'){
                cout << memControler->read(pos);
                namesList[aux++] = memControler->read(pos++);
            }
        }
        pos++;
    }// end of while

    return namesList;
}

