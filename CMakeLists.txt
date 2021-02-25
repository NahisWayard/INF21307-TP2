cmake_minimum_required(VERSION 3.13)

project(INF21307-TP2)

set(CMAKE_CXX_COMPILER_VERSION 17)

SET(CMAKE_CXX_FLAGS "-W -Wall -Wextra -iquote ${PROJECT_SOURCE_DIR}/src/")

file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(tp ${SRC})