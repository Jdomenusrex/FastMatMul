#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstddef>

using Matrix = std::vector<std::vector<double>>;

Matrix random_matrix(size_t n);
bool are_matrices_equal(const Matrix &A, const Matrix &B, double tol = 1e-9);

#endif