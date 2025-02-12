#ifndef MATMUL_H
#define MATMUL_H

#include <vector>
#include <cstddef>

using Matrix = std::vector<std::vector<double>>;

Matrix naive_multiply(const Matrix &A, const Matrix &B);
Matrix blocked_multiply(const Matrix &A, const Matrix &B, size_t block_size);
Matrix random_matrix(size_t n);
bool are_matrices_equal(const Matrix &A, const Matrix &B, double tol = 1e-9);

#endif