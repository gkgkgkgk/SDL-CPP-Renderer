cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

set(SDL2_INCLUDE_DIR /usr/include/SDL2)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# add the executable
add_executable(renderer renderer.cpp)
target_link_libraries(renderer ${SDL2_LIBRARIES})