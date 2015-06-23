#ifndef SHIPCLASS_HPP_INCLUDED
#define SHIPCLASS_HPP_INCLUDED


class ShipClass :: public Ship
{
public:



protected:

    ShipClass();
    ~ShipClass();



private:

//liste de tout les Objets
    static std::vector<ShipClass*> a_shipClassList;
//numero d'identification de l'Objet
    int a_shipClassID;


};


#endif // SHIP_HPP_INCLUDED
