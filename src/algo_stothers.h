#ifndef ALGO_STOTHERS_H
#define ALGO_STOTHERS_H
#include "algo.h"

class StothersAlgo : public Algo {
public:
    Matrix multiply(const Matrix &A, const Matrix &B) const override;
    std::string name() const override { return "Stothers"; }
private:
    static constexpr size_t THRESHOLD = 64;
    Matrix add_matrices(const Matrix &A, const Matrix &B) const;
    Matrix subtract_matrices(const Matrix &A, const Matrix &B) const;
    Matrix recursive_multiply(const Matrix &A, const Matrix &B) const;
    Matrix standard_multiply(const Matrix &A, const Matrix &B) const;
    Matrix get_submatrix(const Matrix &M, size_t row, size_t col, size_t size) const;
    void set_submatrix(Matrix &C, const Matrix &M, size_t row, size_t col) const;
};
#endif