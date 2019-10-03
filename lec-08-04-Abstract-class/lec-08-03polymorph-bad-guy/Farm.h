#ifndef Farm_H
#define Farm_H
#include <iostream>
#include <string>
#include "Critter.h"
#include <vector>

class Farm
{
public:
    Farm(int spaces = 1); 
    void Add(const Critter& aCritter);
    void RollCall() const;
    
private:
    vector<Critter> m_Critters;
};


#endif


