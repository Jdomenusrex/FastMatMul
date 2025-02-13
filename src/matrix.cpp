#include "matrix.h"
#include <random>
#include <cmath>

Matrix random_matrix(size_t n) {
    Matrix M(n, std::vector<double>(n));
    std::mt19937 rng(42);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            M[i][j] = dist(rng);
    return M;
}

bool are_matrices_equal(const Matrix &A, const Matrix &B, double tol) {
    if (A.size() != B.size() || A[0].size() != B[0].size())
        return false;
    for (size_t i = 0; i < A.size(); ++i)
        for (size_t j = 0; j < A[0].size(); ++j)
            if (std::fabs(A[i][j] - B[i][j]) > tol)
                return false;
    return true;
}