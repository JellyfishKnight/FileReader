#include "Components.hpp"
#include <vector>

namespace file_handler {

FileStruct::FileStruct(const std::string& name) : struct_name(name) {}

FileStruct::FileStruct(const std::string& name, const std::string& value) :
    struct_name(name), struct_value(value), is_leaf(true) {}

FileStruct::FileStruct(const std::string& name, const std::map<std::string, FileStruct>& file_struct) :
    struct_name(name), file_struct(file_struct), is_leaf(false) {}

FileStruct& FileStruct::operator[](const std::string &s) {
    if (is_leaf) {
        throw std::runtime_error("Cannot access operator[] on a leaf node");
    } else {
        auto it = file_struct.find(s);
        if (it == file_struct.end()) {
            throw std::runtime_error("Key not found");
        } 
        return it->second;
    }

}

template<typename TType>
TType FileStruct::as() {
    // string conversion
    if (typeid(TType) == typeid(std::string)) {
        return struct_value;
    }
    if (typeid(TType) == typeid(std::vector<TType>)) {
        return stvec<TType>();
    }
    // numeric conversion
    double value = std::stod(struct_value);
    return static_cast<TType>(value);
}

template<typename TType>
std::vector<TType> FileStruct::stvec() {
    if (typeid(TType) == typeid(std::string)) {
        std::vector<std::string> vec;
        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        while ((pos = struct_value.find(delimiter)) != std::string::npos) {
            token = struct_value.substr(0, pos);
            vec.push_back(token);
            struct_value.erase(0, pos + delimiter.length());
        }
        vec.push_back(struct_value);
        return vec;
    } else {
        std::vector<TType> vec;
        std::vector<std::string> vec_str;
        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        while ((pos = struct_value.find(delimiter)) != std::string::npos) {
            token = struct_value.substr(0, pos);
            vec_str.push_back(token);
            struct_value.erase(0, pos + delimiter.length());
        }
        vec_str.push_back(struct_value);
        for (const auto& s : vec_str) {
            double value = std::stod(s);
            vec.push_back(static_cast<TType>(value));
        }
        return vec;
    }
}


} // namespace file_handler