enable_testing()

add_executable(test_matmul test_matmul.cpp)
target_link_libraries(test_matmul PRIVATE matmul)
target_include_directories(test_matmul PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_test(NAME test_matmul COMMAND test_matmul)
set_tests_properties(test_matmul PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})