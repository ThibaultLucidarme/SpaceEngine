#include"InputManager.hpp"


InputManager::InputManager(std::string personalDataFilename, std::string classDataFilename)
{
    a_personalDataLoader = new DataReader(personalDataFilename);
    a_classDataLoader = new DataReader(classDataFilename);
}

InputManager::InputManager(InputManager &in):a_personalDataLoader( in.a_personalDataLoader),a_classDataLoader( in.a_classDataLoader)
{

}

InputManager::~InputManager()
{
    delete a_personalDataLoader;
    delete a_classDataLoader;
}

 DataReader* InputManager::GetPersonalDataLoader()
{
    return a_personalDataLoader;
}

 DataReader* InputManager::GetClassDataLoader()
{
    return a_classDataLoader;
}


