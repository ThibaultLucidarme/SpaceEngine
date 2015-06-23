#include"InputManager.hpp"

InputManager::InputManager(const std::string& class_data_filename, const std::string& personal_data_filename): a_classDataLoader(make(class_data_filename)), a_personalDataLoader(make(personal_data_filename))
  { }


