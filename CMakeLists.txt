cmake_minimum_required(VERSION 3.10)
project(FastMatMul)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(matmul src/matmul.cpp)
include_directories(${CMAKE_SOURCE_DIR}/src)
target_include_directories(matmul PUBLIC ${CMAKE_SOURCE_DIR}/src)

enable_testing()
add_subdirectory(tests)