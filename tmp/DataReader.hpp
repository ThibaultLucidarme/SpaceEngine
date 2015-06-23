#include<fstream>
#include<functional>
#include<iostream>
#include<memory>
#include<stdexcept>
#include<string>
#include<utility>

class DataReader
{
  DataReader(DataReader&&);
  DataReader& operator=(DataReader&&);

  std::ifstream _file;

public:

  DataReader(const std::string& filename);

  int LoadObjectData(const std::string& name);

};


