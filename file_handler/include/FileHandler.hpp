#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>



namespace file_handler {

enum struct FileMode {
    READ = 1,
    WRITE = 2,
    APPEND = 4,
    TRUNCATE = 8,
};

enum struct FileStatus {
    SUCCESS = 0,
    FAIL,
};






class FileHandler {
public:
    FileHandler();

    FileHandler(const std::string& file_path);

    FileHandler(const std::string& file_path, const FileMode& mode);

    ~FileHandler();

    FileStatus open(const std::string& file_path);

    FileStatus open(const std::string& file_path, const FileMode& mode);

    FileStatus close();

    bool is_open();

    std::string operator[](const std::string& s);
private:
    std::string file_path; 



    std::unique_ptr<FileStruct> file_struct;

};


}