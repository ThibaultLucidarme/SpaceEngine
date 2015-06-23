#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "InputManager.hpp"

class Object;

class Object
{
public:

    Object(std::string personalDataFilename, std::string classDataFilename);
    Object(Object& ob);
    ~Object();

    //accessors
    const int GetObjectID();

    void Idle();

protected:

    InputManager a_inputManager;
    std::string a_personalDataFilename;
    std::string a_classDataFilename;

private:

//liste de tout les Objets
    static std::vector<Object*> a_objectList;
//numero d'identification de l'Objet
    int a_objectID;





};


#endif // OBJECT_HPP_INCLUDED
