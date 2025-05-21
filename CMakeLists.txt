cmake_minimum_required(VERSION 3.10)
project(FinalProject)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/Clue.cpp
    src/Item.cpp
    src/Location.cpp
)

# Executable
add_executable(FinalProject ${SOURCES})
