add_library(matmul STATIC matmul.cpp strassen.cpp)

add_executable(FastMatMul main.cpp)
target_link_libraries(FastMatMul PRIVATE matmul)
