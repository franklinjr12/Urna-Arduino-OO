#ifndef URN_H
#define URN_H

#include "Memory.h"
#include "MemoryControler.h"
#include "Arduino.h"

class Candidate{

private:
    String name;
    int votes;

public:
    //Candidate(char* candName){this->name = candName; this->votes = 0;}
    void setVote(int voteNum){this->votes = voteNum;}
    void setName(String candName){this->name = candName;}
    String getName(){return this->name;}
    int getVotes(){return this->votes;}
};


class UrnSetup{

    public:

        // erase all memory with '!'
        int newElection();

        // write cand's name and 00 to it's vote
        int addCandidate(Candidate cand);

        //ordinary constructor
        UrnSetup(MemoryControler* mc, Memory* m);

    private:
        MemoryControler* memControler;
        Memory* memory;
};

class UrnElection{

    public:

        int vote(Candidate cand);
        int getNumberCandidates();
        Candidate* listCandidates();    //returns an array of candidates with size of getNunberCandidates()
        UrnElection(MemoryControler* mc, Memory* m);

    private:
        MemoryControler* memControler;
        Memory* memory;
        int numberOfCandidates;
};

class Urn{
};

#endif // URN_H
