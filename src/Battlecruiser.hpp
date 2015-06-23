#ifndef BATTLECRUISER_HPP_INCLUDED
#define BATTLECRUISER_HPP_INCLUDED

#include "Ship.hpp"

class Battlecruiser;

class Battlecruiser : public Ship
{
public:

    Battlecruiser( std::string configFilename);
    ~Battlecruiser();



protected:



private:

//liste de tout les Objets
    static std::vector<Battlecruiser*> a_battlecruiserList;



};

#endif // BATTLECRUISER_HPP_INCLUDED
