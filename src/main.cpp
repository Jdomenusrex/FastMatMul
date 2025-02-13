#include "algo_naive.h"
#include "algo_block.h"
#include "algo_strassen.h"
#include "algo_winograd.h"
#include <iostream>
#include <chrono>
#include <memory>
#include <vector>

using namespace std;

struct BenchmarkResult {
    size_t size;
    string algo_name;
    double time;
    double gflops;
};

double benchmark(const Algo& algo, const Matrix &A, const Matrix &B, size_t iterations) {
    double total = 0.0;
    for (size_t i = 0; i < iterations; ++i) {
        auto start = chrono::high_resolution_clock::now();
        Matrix C = algo.multiply(A, B);
        auto end = chrono::high_resolution_clock::now();
        total += chrono::duration<double>(end - start).count();
    }
    return total / iterations;
}

double calculate_gflops(size_t n, double time) {
    double ops = 2.0 * n * n * n;
    return (ops / time) / 1e9;
}

int main() {
    vector<unique_ptr<Algo>> algorithms;

    // ADD ALGO HERE

    algorithms.push_back(make_unique<NaiveAlgo>());
    algorithms.push_back(make_unique<BlockedAlgo>(32));
    algorithms.push_back(make_unique<StrassenAlgo>());
    algorithms.push_back(make_unique<WinogradAlgo>());

    vector<size_t> sizes = {64, 128, 256, 512};
    size_t iterations = 3;
    vector<BenchmarkResult> results;

    for (auto s : sizes) {
        Matrix A = random_matrix(s);
        Matrix B = random_matrix(s);
        
        for (const auto& algo : algorithms) {
            double time = benchmark(*algo, A, B, iterations);
            double gflops = calculate_gflops(s, time);
            results.push_back({s, algo->name(), time, gflops});
        }
    }

    cout << "---BEGIN_CSV---" << endl;
    cout << "size,algorithm,time,gflops" << endl;
    for (const auto& r : results) {
        cout << r.size << "," 
             << r.algo_name << "," 
             << r.time << "," 
             << r.gflops << endl;
    }
    cout << "---END_CSV---" << endl;

    return 0;
}