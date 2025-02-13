#include "algo_strassen.h"

Matrix StrassenAlgo::multiply(const Matrix &A, const Matrix &B) const {
    size_t n = A.size();
    size_t padded_size = next_power_of_two(n);
    
    if (padded_size != n) {
        Matrix padded_A = pad_matrix(A, padded_size);
        Matrix padded_B = pad_matrix(B, padded_size);
        Matrix padded_result = strassen2x2(padded_A, padded_B);
        return unpad_matrix(padded_result, n);
    }
    
    return strassen2x2(A, B);
}

Matrix StrassenAlgo::strassen2x2(const Matrix &A, const Matrix &B) const {
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

Matrix StrassenAlgo::pad_matrix(const Matrix &M, size_t size) const {
    Matrix result(size, std::vector<double>(size, 0.0));
    for (size_t i = 0; i < M.size(); ++i)
        for (size_t j = 0; j < M[0].size(); ++j)
            result[i][j] = M[i][j];
    return result;
}

Matrix StrassenAlgo::unpad_matrix(const Matrix &M, size_t original_size) const {
    Matrix result(original_size, std::vector<double>(original_size));
    for (size_t i = 0; i < original_size; ++i)
        for (size_t j = 0; j < original_size; ++j)
            result[i][j] = M[i][j];
    return result;
}

size_t StrassenAlgo::next_power_of_two(size_t n) const {
    size_t power = 1;
    while (power < n) power *= 2;
    return power;
}

Matrix StrassenAlgo::add_matrices(const Matrix &A, const Matrix &B) const {
    size_t n = A.size();
    Matrix C(n, std::vector<double>(n));
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix StrassenAlgo::subtract_matrices(const Matrix &A, const Matrix &B) const {
    size_t n = A.size();
    Matrix C(n, std::vector<double>(n));
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}