#include "Object.hpp"

//initialization of class attributes
std::vector<Object*> Object::a_objectList;

//Constructor
Object::Object(std::string personalDataFilename, std::string classDataFilename):a_inputManager(personalDataFilename, classDataFilename)
{
    a_objectList.push_back(this);
    this->a_objectID = a_objectList.size();

    a_personalDataFilename = personalDataFilename;
    a_classDataFilename = classDataFilename;

}

//copy constructor
Object::Object(Object& ob):a_inputManager( ob.a_inputManager)
{
    a_objectList.push_back(this);
    this->a_objectID = a_objectList.size();

    this->a_personalDataFilename = ob.a_personalDataFilename;
    this->a_classDataFilename = ob.a_classDataFilename;
}
//Destructor
Object::~Object()
{
    a_objectList.erase ( a_objectList.begin() + this->a_objectID -1);

    for (unsigned int i=0 ; i<a_objectList.size(); i++)
        a_objectList[i]->a_objectID = i+1;

}

void Object::Idle(void)
{

}

const int Object::GetObjectID()
{
    return a_objectID;
}







