#ifndef TURRET_HPP_INCLUDED
#define TURRET_HPP_INCLUDED

#include "Equipement.hpp"

typedef enum position {FRONT, BACK, LEFT, RIGHT} position;

class Turret : public Equipement
{
private:
    position a_position;
   // Weapon a_weapon;

};

#endif // TURRET_HPP_INCLUDED
