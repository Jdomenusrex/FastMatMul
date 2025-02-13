#include "algo_stothers.h"

Matrix StothersAlgo::multiply(const Matrix &A, const Matrix &B) const {
    if (A.size() <= THRESHOLD)
        return standard_multiply(A, B);
    return recursive_multiply(A, B);
}
Matrix StothersAlgo::recursive_multiply(const Matrix &A, const Matrix &B) const {
    size_t n = A.size();
    if (n <= THRESHOLD)
        return standard_multiply(A, B);
    size_t k = n / 2;
    Matrix A11 = get_submatrix(A, 0, 0, k);
    Matrix A12 = get_submatrix(A, 0, k, k);
    Matrix A21 = get_submatrix(A, k, 0, k);
    Matrix A22 = get_submatrix(A, k, k, k);
    Matrix B11 = get_submatrix(B, 0, 0, k);
    Matrix B12 = get_submatrix(B, 0, k, k);
    Matrix B21 = get_submatrix(B, k, 0, k);
    Matrix B22 = get_submatrix(B, k, k, k);
    Matrix M1 = recursive_multiply(add_matrices(A11, A22), add_matrices(B11, B22));
    Matrix M2 = recursive_multiply(add_matrices(A21, A22), B11);
    Matrix M3 = recursive_multiply(A11, subtract_matrices(B12, B22));
    Matrix M4 = recursive_multiply(A22, subtract_matrices(B21, B11));
    Matrix M5 = recursive_multiply(add_matrices(A11, A12), B22);
    Matrix M6 = recursive_multiply(subtract_matrices(A21, A11), add_matrices(B11, B12));
    Matrix M7 = recursive_multiply(subtract_matrices(A12, A22), add_matrices(B21, B22));
    Matrix C11 = add_matrices(subtract_matrices(add_matrices(M1, M4), M5), M7);
    Matrix C12 = add_matrices(M3, M5);
    Matrix C21 = add_matrices(M2, M4);
    Matrix C22 = add_matrices(subtract_matrices(add_matrices(M1, M3), M2), M6);
    Matrix C(n, std::vector<double>(n, 0.0));
    set_submatrix(C, C11, 0, 0);
    set_submatrix(C, C12, 0, k);
    set_submatrix(C, C21, k, 0);
    set_submatrix(C, C22, k, k);
    return C;
}
Matrix StothersAlgo::standard_multiply(const Matrix &A, const Matrix &B) const {
    size_t n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            for (size_t k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}
Matrix StothersAlgo::get_submatrix(const Matrix &M, size_t row, size_t col, size_t size) const {
    Matrix sub(size, std::vector<double>(size));
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            sub[i][j] = M[row + i][col + j];
    return sub;
}
void StothersAlgo::set_submatrix(Matrix &C, const Matrix &M, size_t row, size_t col) const {
    size_t size = M.size();
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            C[row + i][col + j] = M[i][j];
}
Matrix StothersAlgo::add_matrices(const Matrix &A, const Matrix &B) const {
    size_t n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
Matrix StothersAlgo::subtract_matrices(const Matrix &A, const Matrix &B) const {
    size_t n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}