cmake_minimum_required(VERSION 3.10)
project(UDPilot)

set(CMAKE_CXX_COMPILER g++)

message(STATUS "Source dir: ${CMAKE_SOURCE_DIR}")
message(STATUS "Output dir will be: ${CMAKE_SOURCE_DIR}/release_project")

add_executable(main core/src/main.cpp)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/release_project"
)

# Выводим итоговый путь
get_target_property(OUTPUT_DIR main RUNTIME_OUTPUT_DIRECTORY)
message(STATUS "Target output directory: ${OUTPUT_DIR}")