cmake_minimum_required(VERSION 3.12)

# set c++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sample_glfw_glad)

find_package(OpenGL REQUIRED)

# add deps
add_subdirectory(external)

# compile sources
add_subdirectory(src)
