#pragma once

#include <exception>


namespace file_handler {


class ElementNotExistException : public std::exception {
    const char* what() const noexcept override {
        return "Element not exists in file";
    }
};

class FileNotExistException : public std::exception {
public:
    const char* what() const noexcept override {
        return "File not exists, check file path please";
    }
};

}
