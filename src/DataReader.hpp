#ifndef DATAREADER_HPP_INCLUDED
#define DATAREADER_HPP_INCLUDED

#include<fstream>
#include<functional>
#include<iostream>
#include<memory>
#include<stdexcept>
#include<string>
#include<utility>
#include<vector>

class DataReader
{
    DataReader(DataReader&&);
    DataReader& operator = (DataReader&&);

    std::ifstream _file;

public:
    DataReader(const std::string& filename);

    template<class type>
    type LoadObjectData(const std::string& name)
    {
        std::string _name;
        type _value;

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


//    std::string LoadObjectData(const std::string& name);
    std::vector<std::string> LoadObjectData(const std::vector<std::string>& name);
};



#endif

