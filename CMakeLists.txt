cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games_Engineering)

SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")

file(GLOB_RECURSE SOURCES practical_1/*.cpp practical_1/*.h)
add_executable(PRACTICAL_1 ${SOURCES})
target_include_directories(PRACTICAL_1 PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_1 sfml-graphics)