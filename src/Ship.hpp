#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include "Object.hpp"
#include "Equipement.hpp"
#include "Turret.hpp"

class Ship;

class Ship : public Object
{
public:


protected:

//constructeurs protected ~ class abstraite
    Ship(std::string classDataFilename, std::string shipDataFilename );
    ~Ship();

//some protected methods test if works as private
//used in constructor EXCLUSIVELY
    void LoadShipClassData( std::string classDataFilename);
    void LoadShipData( std::string classDataFilename);
    void LoadShipAvailableEquipement( std::string equipementDataFilename);
    void LoadShipAllowedEquipement( std::string equipementDataFilename);
    void ApplyEquipement();

private:

//list of all Objects
    static std::vector<Ship*> a_shipList;
//Identification number of the Objet
    int a_shipID;

//class inherent attibutes : loaded in LoadShipClassData
    int a_nbTurretFwdMax, a_nbTurretBckwdMax, a_nbTurretLMax, a_nbTurretRMax;
    int a_inertia;//modifier to limit rudder and speed per enginePower of big ships. as well as wpnPower of small ships
    int a_storage;


//equipement inherente attibutes : loaded in LoadShipData
    int a_nbTurretFwd, a_nbTurretBckwd, a_nbTurretL, a_nbTurretR;
    int a_rudder; //rpm
    int a_acceleration, a_deceleration; // units/sec

    int a_currentShield;
    int a_shieldMax;// given by shields
    int a_currentShieldGen;// given shieldGenMax*energyAllocatedToShield
    int a_shieldGenMax;

    int a_currentWpnEnergy;
    int a_wpnStoMax;// given by wpnGenerator
    int a_currentwpnEnergyGen;// given wpnGenMax*energyAllocatedToWpn
    int a_wpnGenMax;

    int a_currentSpeed;
    int a_speedMax; // given by engines
    int a_currentSpeedMax; // given speedMax*energyAllocatedToEngine

    int a_energyGen; // units/sec
    int a_energySto, a_energyStoMax;
    int a_energyAllocatedShield, a_energyAllocatedEngine, a_energyAllocatedWpn;

    std::vector<Turret*> a_fwdTurretList;
    std::vector<Turret*> a_bckwdTurretList;
    std::vector<Turret*> a_LTurretList;
    std::vector<Turret*> a_RTurretList;

//caracteristic equipement of the ship
    std::vector<Equipement*> a_allowedEquipementList;
    std::vector<Equipement*> a_availableEquipementList;

};


#endif // SHIP_HPP_INCLUDED
