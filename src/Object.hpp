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

	template<class type>
	type LoadClassData(const std::string& varName)
	{
		a_inputManager.ReadClassData(varName);
	}

	template<class type>
	type LoadPersonalData(const std::string& varName)
	{
		a_inputManager.ReadPersonalData(varName);
	}

    void Idle();
	void Move();
	void Display();

protected:

    InputManager a_inputManager;

private:

//liste de tout les Objets
    static std::vector<Object*> a_objectList;
//numero d'identification de l'Objet
    int a_objectID;





};


#endif // OBJECT_HPP_INCLUDED
