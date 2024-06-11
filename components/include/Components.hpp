#pragma once

#include <bits/types/FILE.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <exception>

namespace file_handler {


class FileStruct {
public:
    FileStruct() = default;

    FileStruct(const std::string& name);

    FileStruct(const std::string& name, const std::string& value);

    FileStruct(const std::string& name, const std::map<std::string, FileStruct>& file_struct);

    // use operator[] to get the struct or string
    FileStruct& operator[](const std::string& s);

    template<typename TType>
    TType as();
private:
    
    template<typename TType>
    std::vector<TType> stvec();


    std::map<std::string, FileStruct> file_struct;
    std::string struct_name;
    std::string struct_value;
    bool is_leaf;
    bool value_is_vector;
};



}