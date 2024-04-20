cmake_minimum_required(VERSION 3.28)

project(flake_core)

include_directories(./)

file(
    GLOB_RECURSE flake_core_source

    flake/*.h
    flake/*.cpp
)

add_library(${PROJECT_NAME} STATIC ${flake_core_source})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS OFF)

