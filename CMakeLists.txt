cmake_minimum_required(VERSION 3.25)

set(DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

project(Visual_Lua)


set(CMAKE_CXX_STANDARD 20)

# Specify the directory to create
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")
set(DEPS_LOCATION "${CMAKE_SOURCE_DIR}/deps")

# Create the build directory
file(MAKE_DIRECTORY ${BUILD_DIR})

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)

add_executable(VisualLua src/main.cpp)

# add dependencies
include(cmake/CPM.cmake)

CPMAddPackage("gh:glfw/glfw#3.4")

target_link_libraries(VisualLua glfw)
