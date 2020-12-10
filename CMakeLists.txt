cmake_minimum_required(VERSION 3.8)
project(refactor-gilded-rose-c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib)
