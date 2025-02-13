cmake_minimum_required(VERSION 3.10)
project(FastMatMul)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(matmul STATIC
    src/matrix.cpp
    src/algo_naive.cpp
    src/algo_block.cpp
    src/algo_strassen.cpp
    src/algo_winograd.cpp
)
target_include_directories(matmul PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(FastMatMul src/main.cpp)
target_link_libraries(FastMatMul PRIVATE matmul)

option(BUILD_TESTING "Build the testing tree." ON)

if(BUILD_TESTING)
    enable_testing()
    
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)

    add_executable(test_matmul tests/test_matmul.cpp)
    target_link_libraries(test_matmul PRIVATE matmul gtest gtest_main)

    include(GoogleTest)
    gtest_discover_tests(test_matmul)
endif()