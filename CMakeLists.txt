cmake_minimum_required(VERSION 3.28)

project(flake_core)

file(
    GLOB_RECURSE sources

    flake/*.h
    flake/*.cpp
)

add_library(${PROJECT_NAME} STATIC ${sources})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS OFF)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
