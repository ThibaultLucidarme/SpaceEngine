#include "DataReader.hpp"


  DataReader::DataReader(const std::string& filename): _file(filename.c_str())
  { 
    if(_file.fail())
      throw std::runtime_error("Fail to open " + filename);
  }



  int DataReader::LoadObjectData(const std::string& name)
  {
    std::string _name;
    int _value;

    do
    {
      if(_file >> _name >> _value) ;
      else 
      {
        _file.seekg(0);
        _file.clear(_file.rdstate() & std::ios_base::badbit);
        throw std::runtime_error("Error when lookup for " + name);
      }
    }
    while(_name!=name);

    _file.seekg(0);

    return _value;
  }
