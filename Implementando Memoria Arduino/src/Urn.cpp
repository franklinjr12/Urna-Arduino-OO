#include "Urn.h"


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

int UrnSetup::addCandidate(char* name, int nameSize){
     //error tests
    if(memory == 0) return -1;
    if(memControler == 0) return -1;

    //searching for a free space in the memory
    int pos = 0;    //to mark the position to write the name
    while(pos < memory->memorySize){
        if(memControler->read(pos) == '!' && memControler->read(pos+1) == '!'){ //finding valid position
            //pos++;  //to let one '!' behind
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
    while(memControler->read(pos) != '!'){ //&& memControler->read(pos+1) != '!'){
        listSize++;
        pos++;
    }// end of while


    //putting the names in a list
    pos = 0;
    int aux = 0;
    char* namesList = new char[listSize+1]; //the "+1" is for the '\0' char
    while(memControler->read(pos) != '!'){ //&& memControler->read(pos+1) != '!'){
        namesList[aux++] = memControler->read(pos++);
    }// end of while

    //putting the '\0' end char in the final position
    namesList[listSize] = '\0';

    return namesList;
}


int UrnElection::vote(char* name, int nameSize){
     //error tests
    if(memory == 0) return -1;
    if(memControler == 0) return -1;
    if(name == 0) return -1;

    int flag = 0;
    int i;
    int pos = 0;
    //schearching on the memory for the name
    while(memControler->read(pos) != '!'){
        if(memControler->read(pos) == name[0]){
            for(i = 0; i < nameSize; i++){
                if(name[i] == memControler->read(pos++));
                else break;
                if(i == nameSize-1) flag = 1;
            }//end of for
        }//end of if

        if(flag){ //the name has been found
            //increase the vote
            char number = memControler->read(pos+1);
            if(number < '9')
                memControler->write(number+1, pos+1);
            else{
                number = memControler->read(pos);
                number++;
                memControler->write(number, pos);
                memControler->write('0', pos+1);
            }
            return 0;
        }

        pos++;
    }//end of while

    return -1;
}
