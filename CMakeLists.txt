cmake_minimum_required(VERSION 3.22)

set(DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

project(Visual_Lua)


set(CMAKE_CXX_STANDARD 20)

# Create the build directory
file(MAKE_DIRECTORY "./build")

# Specify the directory to create
set(BUILD_DIR "./build")
set(DEPS_LOCATION "${CMAKE_CURRENT_LIST_DIR}/deps")
set(IMGUI_LOCATION "${DEPS_LOCATION}/imgui-1.91.4-docking")

include_directories(src/include
        deps/imgui-1.91.4-docking)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)

file(GLOB IMGUI_SOURCES
       "${IMGUI_LOCATION}/*.cpp"
        "${IMGUI_LOCATION}/backends/imgui_impl_glfw.cpp"
       "${IMGUI_LOCATION}/backends/imgui_impl_opengl3.cpp"
)


add_executable(VisualLua
        src/main.cpp
        src/glfwinstance.h
        src/glfwinstance.cpp
        src/iwindowmanager.h
        src/window.h
        src/window.cpp
        src/windowmanager.h
        src/windowmanager.cpp
        src/exceptions.h
        src/exceptions.cpp
        )

target_sources(VisualLua PRIVATE ${IMGUI_SOURCES})

# add dependencies
include(cmake/CPM.cmake)

CPMAddPackage("gh:glfw/glfw#3.4")

target_link_libraries(VisualLua glfw GL)

target_include_directories(VisualLua PRIVATE ${IMGUI_LOCATION})
