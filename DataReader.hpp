#ifndef DATAREADER_HPP_INCLUDED
#define DATAREADER_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

class DataReader
{
public:
    DataReader( const std::string& filename);
    DataReader( DataReader& dr);
    ~DataReader();

    void LoadObjectData( int &variable, std::string variableName);
    void LoadObjectData( std::string &variable, std::string variableName);
    void LoadObjectData( std::vector<std::string> &variable, std::string variableName, int &storageCapacityLeft);

private:

    std::string a_filename;
    std::ifstream a_file;



};





#endif

