#include "InputManager.hpp"

InputManager::InputManager(const std::string& class_data_filename, const std::string& personal_data_filename): _ClassDataLoader(_make(class_data_filename)), _PersonalDataLoader(_make(personal_data_filename))
  { }

  int InputManager::ReadClassData(const std::string& name)
 { 
    return _ClassDataLoader->LoadObjectData(name);
  }

  int InputManager::ReadPersonalData(const std::string& name)
 { 
    return _PersonalDataLoader->LoadObjectData(name);
  }

