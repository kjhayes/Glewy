cmake_minimum_required(VERSION 3.19)

project(GLEWY VERSION 1.0)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

install(TARGETS ${CMAKE_PROJECT_NAME} LIBRARY)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/Glewy TYPE INCLUDE)