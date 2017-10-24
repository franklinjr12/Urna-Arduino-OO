#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "Arduino.h"

class Candidate{

private:
    char* name;
    int votes;

public:
    //Candidate(char* candName){this->name = candName; this->votes = 0;}
    void setVote(int voteNum){this->votes = voteNum;}
    void setName(char* candName){this->name = candName;}
    char* getName(){return this->name;}
    int getVotes(){return this->votes;}
};






#endif // CANDIDATE_H
