#ifndef INPUTMANAGER_HPP_INCLUDED
#define INPUTMANAGER_HPP_INCLUDED

#include "DataReader.hpp"

class InputManager
{
public:

    InputManager(std::string personalDataFilename, std::string classDataFilename);
    InputManager(InputManager &in);
    ~InputManager();

     DataReader* GetPersonalDataLoader();
     DataReader* GetClassDataLoader();

protected:



private:

    DataReader* a_personalDataLoader;
    DataReader* a_classDataLoader;

};

#endif // INPUTMANAGER_HPP_INCLUDED
