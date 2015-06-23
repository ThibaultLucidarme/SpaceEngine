#include "Equipement.hpp"


//initialisation des attributs de classe
std::vector<Equipement*> Equipement::a_equipementList;

//Constructor
Equipement::Equipement(std::string personalDataFilename, std::string classDataFilename):Object( personalDataFilename, classDataFilename)
{
    a_equipementList.push_back(this);

}

Equipement::Equipement(const Equipement &eq):Object( (Object&)eq)
{
    this->a_equipementName = eq.a_equipementName;
    this->a_type = eq.a_type;
    this->a_value = eq.a_value;

    //a_equipementList est recopiée
    //tester si this est ajouté ou pas.
    a_equipementList.push_back(this);
}

//Destructeur
Equipement::~Equipement()
{
    unsigned int i=0 ;

    while ( i<a_equipementList.size() )
    {
        if(a_equipementList[i]->GetObjectID() == this->GetObjectID() )
            a_equipementList.erase ( a_equipementList.begin() + i-1);
        i++;
    }
}


const int Equipement::GetValue()
{
    return a_value;
}

const std::string Equipement::GetType()
{
    return a_type;
}

const bool Equipement::isIn(std::vector<Equipement*> equipementList)
{
    bool belongs = false;

    std::vector<Equipement*>::iterator it = equipementList.begin();
    while( it<equipementList.end() || this->GetObjectID() != (*it)->GetObjectID())
        it++;
    if( this->GetObjectID() == (*it)->GetObjectID())
        belongs = true;


    return belongs;
}

const Equipement Equipement::lookFor(int equipementID, std::vector<Equipement*> equipementList)
{
    std::vector<Equipement*>::iterator it = equipementList.begin();
    while( it<equipementList.end() && (*it)->GetObjectID() != equipementID)
        it++;
    if((*it)->GetObjectID() == equipementID)
        return **it;
    else
        return **it;//a changer: renvoyer objet null

}

const Equipement Equipement::lookFor(std::string equipementName, std::vector<Equipement*> equipementList)
{
    std::vector<Equipement*>::iterator it = equipementList.begin();
    while( it<equipementList.end() && (*it)->a_equipementName != equipementName)
        it++;
    if((*it)->a_equipementName == equipementName)
        return **it;
    else
        return **it;//a changer: renvoyer objet null

}



