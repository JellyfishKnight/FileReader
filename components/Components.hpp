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
    FileStruct operator[](const std::string& s);
    

private:
    std::map<std::string, FileStruct> file_struct;
    std::map<std::string, std::string> basic_struct;
};



}