cmake_minimum_required(VERSION 3.22.0)

project(file_handler)

target_include_directories(
    ${PROJECT_NAME}
    include
)

add_library(
    ${PROJECT_NAME} STATIC
    src/FileHandler.cpp
)

install(
    TARGETS ${PROJECT_NAME}
    DESTINATION lib/file_handler
)