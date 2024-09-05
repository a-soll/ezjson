cmake_minimum_required(VERSION 3.5)
project(ezjson-test)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Debug")

find_package(ezjson REQUIRED)

add_executable(ezjson-test main.cpp)
set_property(TARGET ezjson-test PROPERTY CXX_STANDARD 17)

target_link_libraries(ezjson-test PUBLIC ezjson::ezjson)
