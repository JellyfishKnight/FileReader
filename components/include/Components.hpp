#pragma once

#include <bits/types/FILE.h>
#include <fstream>
#include <memory>
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



class BaseParser {
public:
    BaseParser() = default;

    virtual ~BaseParser() = default;

    virtual FileStruct parse(const std::string& content) = 0;

    virtual std::string dump(const FileStruct& file_struct) = 0;

    std::shared_ptr<FileStruct> get_root() {
        return root;
    }
protected:
    std::shared_ptr<FileStruct> root;
};

class YamlParser : public BaseParser {
public:
    YamlParser() = default;

    ~YamlParser() = default;

    FileStruct parse(const std::string& content) override;

    std::string dump(const FileStruct& file_struct) override;
};




}