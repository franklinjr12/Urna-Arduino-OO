#ifndef URN_H
#define URN_H

#include "Memory.h"
#include "MemoryControler.h"

class UrnSetup{

    public:

        // erase all memory with '!'
        int newElection();

        // write cand's name and 00 to it's vote
        int addCandidate(char* name, int nameSize);

        //ordinary constructor
        UrnSetup(MemoryControler* mc, Memory* m);

    private:
        MemoryControler* memControler;
        Memory* memory;
};

class UrnElection{

    public:

        int vote(char* name, int nameSize);
        char* listCandidates();
        UrnElection(MemoryControler* mc, Memory* m);

    private:
        MemoryControler* memControler;
        Memory* memory;
};

class Urn{
};

#endif // URN_H
