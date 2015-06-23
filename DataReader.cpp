#include "DataReader.hpp"

DataReader::DataReader(const std::string& filename)
{
    //initialises a_filename
    a_filename = filename;

    //initialises a_file
    a_file.open( a_filename.c_str());

    //tests a_file
    if(!a_file)
    {
        std::cout<<"could not open file\t"<<a_filename<< " : " << strerror(errno) << std::endl;
    }

}

DataReader::DataReader( DataReader& dr)
{
    //initialises a_filename
    this->a_filename = dr.a_filename;

    //initialises a_file
    a_file.open( this->a_filename.c_str());

    //tests a_file
    if(!(this->a_file))
    {
        std::cout<<"could not open file\t"<<a_filename<<std::endl;
        this->~DataReader();
    }
}

DataReader::~DataReader()
{
}



void DataReader::LoadObjectData( int &variable, std::string variableName)
{
    int i = 0;
    std::string tmp = "";
    while ( tmp != ("- "+variableName))//endless loop here: tmp stays empty
    {
        getline(a_file, tmp);

        if( tmp == "/*")// commentary flag. useless here. Put in case of modification of the function
        {
            a_file >> tmp;
            while(tmp != "*/")
                a_file >> tmp;
        }
        std::cout<<i++<<"\t"<<tmp<<std::endl;
    }
    if( tmp != variableName)
    {
        std::cerr<<"Cannot load parameter!\t"<< variableName <<std::endl;
        return ;
    }

    a_file >> variable;
}

void DataReader::LoadObjectData( std::vector<std::string> &variable, std::string variableName, int &storageCapacityLeft)
{
    std::string tmp;
    while ( tmp != variableName )
    {
        a_file >> tmp;

        if( tmp == "/*")// commentary flag. useless here. Put in case of modification of the function
        {
            a_file >> tmp;
            while(tmp != "*/" )
                a_file >> tmp;
        }
    }
    if(tmp != variableName )
    {
        std::cerr<<"Cannot load parameter!\t"<< variableName<<std::endl;
        return ;
    }

    while( tmp != "-")
    {
        std::string data;
        a_file >> data;

        variable.push_back(data);
    }
}

void DataReader::LoadObjectData( std::string &variable, std::string variableName)
{
    std::string tmp;
    while ( tmp != variableName )
    {
        a_file >> tmp;

        if( tmp == "/*")// commentary flag. useless here. Put in case of modification of the function
        {
            a_file >> tmp;
            while(tmp != "*/")
                a_file >> tmp;
        }
    }
    if( tmp != variableName)
    {
        std::cerr<<"Cannot load parameter!\t"<< tmp <<std::endl;
        return ;
    }

    a_file >> variable;
}








