#include "matmul.h"
#include <random>
#include <cmath>

Matrix naive_multiply(const Matrix &A, const Matrix &B) {
    size_t n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            for (size_t k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Matrix blocked_multiply(const Matrix &A, const Matrix &B, size_t block_size) {
    size_t n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (size_t i0 = 0; i0 < n; i0 += block_size)
        for (size_t j0 = 0; j0 < n; j0 += block_size)
            for (size_t k0 = 0; k0 < n; k0 += block_size)
                for (size_t i = i0; i < std::min(i0 + block_size, n); ++i)
                    for (size_t k = k0; k < std::min(k0 + block_size, n); ++k)
                        for (size_t j = j0; j < std::min(j0 + block_size, n); ++j)
                            C[i][j] += A[i][k] * B[k][j];
    return C;
}

Matrix random_matrix(size_t n) {
    Matrix M(n, std::vector<double>(n));
    std::mt19937 rng(42);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            M[i][j] = dist(rng);
    return M;
}

Matrix strassen(const Matrix &A, const Matrix &B) {
    double M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    double M2 = (A[1][0] + A[1][1]) * B[0][0];
    double M3 = A[0][0] * (B[0][1] - B[1][1]);
    double M4 = A[1][1] * (B[1][0] - B[0][0]);
    double M5 = (A[0][0] + A[0][1]) * B[1][1];
    double M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    double M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    return {{
    {M1 + M4 - M5 + M7, M3 + M5},
    {M2 + M4, M1 + M3 - M2 + M6}
    }};
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
