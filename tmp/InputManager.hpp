#include "DataReader.hpp"


class InputManager
{
  static std::unique_ptr<DataReader> _make(const std::string& filename)
  {
    return std::unique_ptr<DataReader>(new DataReader(filename));
  }

  std::unique_ptr<DataReader> _ClassDataLoader;
  std::unique_ptr<DataReader> _PersonalDataLoader;

public:

	//constructor
  InputManager(const std::string& class_data_filename, const std::string& personal_data_filename);
	
  int ReadClassData(const std::string& name);
  int ReadPersonalData(const std::string& name);
};


/*

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
*/

