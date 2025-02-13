# FastMatMul

FastMatMul implements various matrix multiplication algorithms in C++. The project is designed to be modular, making it easy to add new algorithms and compare their performance.

## Project Structure
```
.
├── src/
│   ├── algo.h           # Base algorithm interface
│   ├── algo_naive.h     # Naive multiplication algorithm
│   ├── algo_block.h     # Block multiplication algorithm
│   ├── ...
│   ├── matrix.h         # Matrix utilities
│   └── main.cpp         # Benchmark program
├── tests/
│   ├── test_matmul.cpp  # Unit tests
│   └── ...
├── run_tests.sh         # Script to run tests
└── run_benchmark.sh     # Script to run benchmarks
```

## Building and Running

### Prerequisites
- CMake (>= 3.10)
- C++17 compatible compiler
- Git (for fetching GoogleTest)

### Build and Run Tests
```bash
# Make scripts executable
chmod +x run_tests.sh run_bench.sh

# Run tests
./run_tests.sh
```

### Run Benchmarks
```bash
./run_bench.sh
```
Results will be saved to `build/benchmark_results.csv`

## Adding New Algorithms

1. Create two new files in `src/`:
   ```cpp
   // src/algo_new.h
   #ifndef ALGO_NEW_H
   #define ALGO_NEW_H
   
   #include "algo.h"
   
   class NewAlgorithm : public Algorithm {
   public:
       Matrix multiply(const Matrix &A, const Matrix &B) const override;
       std::string name() const override { return "NewAlgo"; }
   };
   
   #endif

   // src/algo_new.cpp
   #include "algo_new.h"
   
   Matrix NewAlgorithm::multiply(const Matrix &A, const Matrix &B) const {
       // Your implementation here
   }
   ```

2. Add the new source file to CMakeLists.txt:
   ```cmake
   add_library(matmul STATIC
       src/matrix.cpp
       src/algo_naive.cpp
       src/algo_block.cpp
       src/algo_new.cpp    # Add this line
   )
   ```

3. Add the algorithm to benchmarks in main.cpp:
   ```cpp
   #include "algo_new.h"
   
   // In main():
   algorithms.push_back(make_unique<NewAlgorithm>());
   ```

## Adding New Tests

Add new test cases to `tests/test_matmul.cpp`:

```cpp
TEST_F(MatrixMultiplicationTest, NewAlgorithm) {
    NewAlgorithm algo;
    Matrix result = algo.multiply(A, B);
    EXPECT_TRUE(are_matrices_equal(result, expected));
}
```

## Benchmarking Results

The benchmark program tests each algorithm with different matrix sizes and outputs results in CSV format:
```
size,Naive,Blocked,NewAlgo
64,0.001234,0.000987,0.000789
128,0.009876,0.007654,0.006543
...
```

## Implementation Notes

### Matrix Class
The `Matrix` type is defined as:
```cpp
using Matrix = std::vector<std::vector<double>>;
```

### Algorithm Interface
All algorithms implement the `Algorithm` interface:
```cpp
class Algorithm {
public:
    virtual Matrix multiply(const Matrix &A, const Matrix &B) const = 0;
    virtual std::string name() const = 0;
    virtual ~Algorithm() = default;
};
```

## Contributing

1. Fork the repository
2. Create a new branch for your feature
3. Follow the guide above to add your algorithm
4. Add appropriate tests
5. Submit a pull request