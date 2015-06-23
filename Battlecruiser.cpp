#include "Battlecruiser.hpp"

//initialisation des attributs de classe
std::vector<Battlecruiser*> Battlecruiser::a_battlecruiserList;

//Constructor
Battlecruiser::Battlecruiser(std::string dataFile):Ship("BattleCruiser.dat",dataFile)
{
    a_battlecruiserList.push_back(this);
}

//Destructeur
Battlecruiser::~Battlecruiser()
{
    unsigned int i=0 ;
    while( i<a_battlecruiserList.size() )
    {
        if( a_battlecruiserList[i]->GetObjectID() == a_battlecruiserList[i]->GetObjectID() )
            a_battlecruiserList.erase (a_battlecruiserList.begin()+i-1);
        i++;
    }
}

