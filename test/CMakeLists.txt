set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

link_libraries(ezjson)

add_executable(test
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
