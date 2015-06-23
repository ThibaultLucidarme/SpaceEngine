#ifndef EQUIPEMENT_HPP_INCLUDED
#define EQUIPEMENT_HPP_INCLUDED

#include "Object.hpp"

class Equipement;

class Equipement : public Object
{
public:
    Equipement(std::string personalDataFilename, std::string classDataFilename);
    Equipement(const Equipement &eq); //copy's constructor
    ~Equipement();

    //accessors
    const int GetValue( );
    const std::string GetType();
    const bool isIn(std::vector<Equipement*> equipementList);
    static const Equipement lookFor(std::string equipementName, std::vector<Equipement*> equipementList);
    static const Equipement lookFor(int equipementID, std::vector<Equipement*> equipementList);

private:

    static std::vector<Equipement*> a_equipementList;
    std::string a_equipementName;
    std::string a_type;
    int a_value;

};


#endif

