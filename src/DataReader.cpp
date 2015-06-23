#include "DataReader.hpp"


DataReader::DataReader(const std::string& filename): _file(filename.c_str())
    {
        if(_file.fail())
            throw std::runtime_error("Fail to open " + filename);
    }


std::vector<std::string> DataReader::LoadObjectData(const std::vector<std::string>& name)
    {
        std::string _name;
        std::string _value;
	std::vector<std::string> res;
	
	int i=-1;
	
	do{
        do
        {
            if(_file >> _name >> _value) ;
            else
            {
                _file.seekg(0);
                _file.clear(_file.rdstate() & std::ios_base::badbit);
                throw std::runtime_error("Error when lookup for " + _name);
            }
	    
        }
        while(_name!=name[i]);

        _file.seekg(0);
	i++;
	res.push_back(_value);

	}while(i<name.size());

        return res;
    }





