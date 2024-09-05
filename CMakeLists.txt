cmake_minimum_required(VERSION 3.5)
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

set(CMAKE_DEBUG_POSTFIX d)

project(ezjson LANGUAGES CXX VERSION 1.0.0)
include(GNUInstallDirs)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message("Building configuration: ${CMAKE_BUILD_TYPE}")

add_library(ezjson
    ${CMAKE_CURRENT_SOURCE_DIR}/src/json.cpp
)

target_sources(
    ezjson PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES include/ezjson/json.h
)

add_subdirectory(simdjson)

include(CMakePackageConfigHelpers)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ezjson.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/ezjson.pc
    @ONLY
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/ezjson.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ezjson-config-version.cmake
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ezjson-config-version.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ezjson-config.cmake
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/ezjson
)

install(
    TARGETS ezjson
    EXPORT ezjsonTargets
    FILE_SET HEADERS
)

install(
    EXPORT ezjsonTargets
    NAMESPACE ezjson::
    DESTINATION ${CMAKE_INSTALL_DATADIR}/ezjson
)

target_compile_options(ezjson PRIVATE -Wall -Wunused-variable)

target_link_libraries(ezjson PUBLIC simdjson)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
