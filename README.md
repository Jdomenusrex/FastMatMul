# FastMatMul
FastMatMul implements various matrix multiplication algorithms in C++. The project is designed to be modular, making it easy to add new algorithms and compare their performance.

## Project Structure
```
.
├── src/
│   ├── algo.h           # Base algorithm interface
│   ├── algo_naive.h     # Naive multiplication
│   ├── algo_block.h     # Block multiplication
│   ├── ...
│   ├── matrix.h         # Matrix utilities
│   └── main.cpp         # Benchmark program
├── tests/
│   ├── ...
│   └── test_matmul.cpp  # Unit tests
├── run_tests.sh         # Run tests
└── run_bench.sh         # Run benchmarks
```

## Prerequisites
- CMake (>= 3.10)
- C++17 compiler
- Git (for GoogleTest)

## Build & Run
```bash
chmod +x run_tests.sh run_bench.sh
./run_tests.sh    # Run tests
./run_bench.sh    # Run benchmarks
```

## Adding New Algorithms
1. Create header and implementation:
```cpp
// src/algo_new.h
#ifndef ALGO_NEW_H
#define ALGO_NEW_H
#include "algo.h"

class NewAlgo : public Algo {
public:
    Matrix multiply(const Matrix &A, const Matrix &B) const override;
    std::string name() const override { return "NewAlgo"; }
};
#endif
```

2. Implement Algorithm:
```cpp
// src/algo_new.cpp
Matrix NewAlgo::multiply(const Matrix &A, const Matrix &B) const {
    // Implementation
}
```

3. Update CMakeLists.txt:
```cmake
add_library(matmul STATIC
    src/matrix.cpp
    src/algo_naive.cpp
    src/algo_block.cpp
    src/algo_new.cpp
)
```

4. Add to main.cpp:
```cpp
#include "algo_new.h"
algorithms.push_back(make_unique<NewAlgo>());
```

5. Add test in test_matmul.cpp:
```cpp
TEST_F(MatMulTest, NewAlgo) {
    NewAlgo algo;
    Matrix result = algo.multiply(A, B);
    EXPECT_TRUE(are_matrices_equal(result, expected));
}
```

## Implementation
```cpp
using Matrix = std::vector<std::vector<double>>;

class Algo {
public:
    virtual Matrix multiply(const Matrix &A, const Matrix &B) const = 0;
    virtual std::string name() const = 0;
    virtual ~Algo() = default;
};
```
