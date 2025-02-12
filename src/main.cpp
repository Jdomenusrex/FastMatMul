#include "matmul.h"
#include <iostream>
#include <chrono>

using namespace std;

double benchmark(const Matrix &A, const Matrix &B, size_t iterations, bool use_blocked, size_t block_size = 32) {
    double total = 0.0;
    for (size_t i = 0; i < iterations; ++i) {
        auto start = chrono::high_resolution_clock::now();
        Matrix C = use_blocked ? blocked_multiply(A, B, block_size) : naive_multiply(A, B);
        auto end = chrono::high_resolution_clock::now();
        total += chrono::duration<double>(end - start).count();
    }
    return total / iterations;
}

int main() {
    cout << "size,naive,blocked\n";
    std::vector<size_t> sizes = {64, 128, 256, 512};
    size_t iterations = 3;
    size_t block_size = 32;

    for (auto s : sizes) {
        Matrix A = random_matrix(s);
        Matrix B = random_matrix(s);
        double t_naive = benchmark(A, B, iterations, false);
        double t_blocked = benchmark(A, B, iterations, true, block_size);
        cout << s << "," << t_naive << "," << t_blocked << "\n";
    }
    return 0;
}