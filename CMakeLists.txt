cmake_minimum_required(VERSION 3.10)
project(CPPVideoGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(app)
include_directories(src)

add_subdirectory(app)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(extern/googletest)
