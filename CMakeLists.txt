cmake_minimum_required(VERSION 3.19)

project(Glewy VERSION 1.0)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

install(TARGETS GLEWY LIBRARY)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/Glewy TYPE INCLUDE)