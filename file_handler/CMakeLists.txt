cmake_minimum_required(VERSION 3.22.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE DEBUG)


project(file_handler)


add_library(
    ${PROJECT_NAME} STATIC
    src/FileHandler.cpp
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    include
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    components
)

install(
    TARGETS ${PROJECT_NAME}
    DESTINATION lib/file_handler
)