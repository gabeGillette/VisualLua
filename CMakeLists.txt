cmake_minimum_required(VERSION 3.25)
project(Visual_Lua)

set(CMAKE_CXX_STANDARD 20)

# Specify the directory to create
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")

# Create the build directory
file(MAKE_DIRECTORY ${BUILD_DIR})

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)


add_executable(VisualLua src/main.cpp)
