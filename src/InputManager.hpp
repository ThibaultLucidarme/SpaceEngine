#ifndef INPUTMANAGER_HPP_INCLUDED
#define INPUTMANAGER_HPP_INCLUDED

#include "DataReader.hpp"

class InputManager
{
  static std::shared_ptr<DataReader> make(const std::string& filename)
  {
    return std::shared_ptr<DataReader>(new DataReader(filename));
  }

  std::shared_ptr<DataReader> a_classDataLoader;
  std::shared_ptr<DataReader> a_personalDataLoader;

public:

	//constructor
  InputManager(const std::string& class_data_filename, const std::string& personal_data_filename);
	
	template<class type>
  type ReadClassData(const std::string& name)
 { 
    return a_classDataLoader<type>.LoadObjectData(name);
  }

template<class type>
  type ReadPersonalData(const std::string& name)
 { 
    return a_personalDataLoader<type>.LoadObjectData(name);
  }
};



#endif // INPUTMANAGER_HPP_INCLUDED
