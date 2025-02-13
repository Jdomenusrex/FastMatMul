#ifndef ALGO_STRASSEN_H
#define ALGO_STRASSEN_H

#include "algo.h"

class StrassenAlgo : public Algo {
public:
    Matrix multiply(const Matrix &A, const Matrix &B) const override;
    std::string name() const override { return "Strassen"; }
private:
    Matrix strassen2x2(const Matrix &A, const Matrix &B) const;
    Matrix pad_matrix(const Matrix &M, size_t size) const;
    Matrix unpad_matrix(const Matrix &M, size_t original_size) const;
    size_t next_power_of_two(size_t n) const;
    Matrix add_matrices(const Matrix &A, const Matrix &B) const;
    Matrix subtract_matrices(const Matrix &A, const Matrix &B) const;
};

#endif