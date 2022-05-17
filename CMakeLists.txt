cmake_minimum_required(VERSION 3.20)
project(Infernus VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_library(Infernus SHARED)
target_sources(Infernus PRIVATE Infernus.cpp)

add_subdirectory(Includes)

target_link_libraries(Infernus PRIVATE minhook)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})