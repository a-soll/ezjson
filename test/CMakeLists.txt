set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(test)

include_directories(${PROJECT_SOURCE_DIR}/include)

target_sources(test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(test ezjson)
