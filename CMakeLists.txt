cmake_minimum_required(VERSION 3.22.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE DEBUG)

project(file_handler)

add_subdirectory(
    components
)

add_subdirectory(
    file_handler
)

