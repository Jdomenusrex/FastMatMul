#include "algo_winograd.h"

std::vector<double> WinogradAlgo::compute_row_factors(const Matrix &A) const {
    size_t m = A.size();
    size_t k = A[0].size();
    std::vector<double> row_factor(m, 0.0);
    
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < k - 1; j += 2) {
            row_factor[i] += A[i][j] * A[i][j + 1];
        }
    }
    return row_factor;
}

std::vector<double> WinogradAlgo::compute_col_factors(const Matrix &B) const {
    size_t k = B.size();
    size_t n = B[0].size();
    std::vector<double> col_factor(n, 0.0);
    
    for (size_t j = 0; j < n; ++j) {
        for (size_t i = 0; i < k - 1; i += 2) {
            col_factor[j] += B[i][j] * B[i + 1][j];
        }
    }
    return col_factor;
}

Matrix WinogradAlgo::multiply(const Matrix &A, const Matrix &B) const {
    size_t m = A.size();
    size_t n = B[0].size();
    size_t k = A[0].size();
    
    Matrix C(m, std::vector<double>(n, 0.0));
    
    std::vector<double> row_factor = compute_row_factors(A);
    std::vector<double> col_factor = compute_col_factors(B);
    
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            double sum = -row_factor[i] - col_factor[j];
            for (size_t l = 0; l < k - 1; l += 2) {
                sum += (A[i][l] + B[l + 1][j]) * (A[i][l + 1] + B[l][j]);
            }
            if (k % 2 == 1) {
                sum += A[i][k - 1] * B[k - 1][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}
