#include "Ship.hpp"

//initialisation des attributs de classe
std::vector<Ship*> Ship::a_shipList;

//Constructor
Ship::Ship(std::string classDataFilename, std::string shipDataFilename ): Object(shipDataFilename, classDataFilename)
{
    a_shipList.push_back(this);

    //loading the variable values
    LoadShipClassData(a_classDataFilename);
    LoadShipData(a_personalDataFilename);

    //apply equipement modification to attributes
    ApplyEquipement();
}

//Destructeur
Ship::~Ship()
{
    unsigned int i=0 ;
	while( i<a_shipList.size() )
        {
		if( a_shipList[i]->GetObjectID() == a_shipList[i]->GetObjectID() )
			a_shipList.erase (a_shipList.begin()+i-1);
		i++;
	}
}

void Ship::LoadShipClassData(std::string classDataFilename)
{
    a_inputManager.GetClassDataLoader()->LoadObjectData( a_nbTurretFwdMax, "nbTurretFwdMax");
    a_inputManager.GetClassDataLoader()->LoadObjectData( a_nbTurretBckwdMax, "nbTurretBckwdMax");
    a_inputManager.GetClassDataLoader()->LoadObjectData( a_nbTurretRMax, "nbTurretRMax");
    a_inputManager.GetClassDataLoader()->LoadObjectData( a_nbTurretLMax, "nbTurretLMax");
    a_inputManager.GetClassDataLoader()->LoadObjectData( a_inertia, "inertia");
    a_inputManager.GetClassDataLoader()->LoadObjectData( a_storage, "storage");

    LoadShipAllowedEquipement( classDataFilename);
}

void Ship::LoadShipData( std::string shipDataFilename)
{
    a_inputManager.GetPersonalDataLoader()->LoadObjectData( a_nbTurretFwd, "nbTurretFwd");
    a_inputManager.GetPersonalDataLoader()->LoadObjectData( a_nbTurretBckwd, "nbTurretBckwd");
    a_inputManager.GetPersonalDataLoader()->LoadObjectData( a_nbTurretR, "nbTurretR");
    a_inputManager.GetPersonalDataLoader()->LoadObjectData( a_nbTurretL, "nbTurretL");

    //checking
    a_nbTurretFwd = (a_nbTurretFwd<a_nbTurretFwdMax)? a_nbTurretFwd:a_nbTurretFwdMax ;
    a_nbTurretBckwd = (a_nbTurretBckwd<a_nbTurretBckwdMax)?a_nbTurretBckwd:a_nbTurretBckwdMax;
    a_nbTurretL = (a_nbTurretL<a_nbTurretLMax)?a_nbTurretL:a_nbTurretLMax;
    a_nbTurretR = (a_nbTurretR<a_nbTurretRMax)?a_nbTurretR:a_nbTurretRMax;


    LoadShipAvailableEquipement(shipDataFilename);


}

void Ship::LoadShipAvailableEquipement( std::string equipementDataFilename)
{
    Equipement nul();//equivalent du NULL pour un objet de type Equipement
    int i =0;
    //initialisation of the ships list of equipement chosen by the player
    std::vector<std::string> listOfEquipement;
    a_inputManager.GetPersonalDataLoader()->LoadObjectData( listOfEquipement, "availableEquipementList",i);

    //intergration of each Equipement into the ship
    std::vector<std::string>::iterator it;
    for(it= listOfEquipement.begin() ; it<listOfEquipement.end() ; it++)
    {
        Equipement* eq = new Equipement( Equipement::lookFor(*it, a_allowedEquipementList));
        //if (eq != nul)
            a_availableEquipementList.push_back(eq);
        //else            std::cerr<<"could not fit "<< *it" into ship "<< a_shipID<<std::endl;
    }
}

void Ship::LoadShipAllowedEquipement( std::string equipementDataFilename)
{
    int i = 0;
    //initialisation of the ships list of equipement chosen by the player
    std::vector<std::string> listOfEquipement;
    a_inputManager.GetClassDataLoader()->LoadObjectData( listOfEquipement, "allowedEquipementList", i);

    //intergration of each Equipement into the ship
    std::vector<std::string>::iterator it;
    for(it= listOfEquipement.begin() ; it<listOfEquipement.end() ; it++)
    {
        Equipement* eq = new Equipement( Equipement::lookFor(*it, a_allowedEquipementList));
      //  if (!eq)
            a_allowedEquipementList.push_back(eq);
      //  else    std::cerr<<"could not fit "<< *it" into ship "<< a_shipID<<std::endl;
    }
}

void Ship::ApplyEquipement(void)
{
    std::vector<Equipement*>::iterator it;
    for(it= a_availableEquipementList.begin() ; it<a_availableEquipementList.end() ; it++)
    {
        if((*it)->GetType() == "shield")
            a_shieldMax += (*it)->GetValue();
        else if((*it)->GetType() == "shieldGen")
            a_shieldMax += (*it)->GetValue();

        else if((*it)->GetType() == "wpnEnergySto")
            a_wpnStoMax += (*it)->GetValue();
        else if((*it)->GetType() == "wpnEnergyGen")
            a_wpnGenMax += (*it)->GetValue();

        else if((*it)->GetType() == "engine")
            a_speedMax += (*it)->GetValue();

        else if((*it)->GetType() == "energyGen")
            a_energyGen += (*it)->GetValue();
        else if((*it)->GetType() == "energyContainer")
            a_energyStoMax += (*it)->GetValue();

        else if((*it)->GetType() == "boosters")
            a_acceleration += (*it)->GetValue();
        else if((*it)->GetType() == "brakes")
            a_deceleration += (*it)->GetValue();
        else if((*it)->GetType() == "oil_injector")
            a_rudder += (*it)->GetValue();

        else
            std::cerr<<"could not apply "<< (*it)->GetType()<<" to ship "<< a_shipID<<std::endl;


    }

}






