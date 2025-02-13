#ifndef ALGO_WINOGRAD_H
#define ALGO_WINOGRAD_H
#include "algo.h"

class WinogradAlgo : public Algo {
public:
    Matrix multiply(const Matrix &A, const Matrix &B) const override;
    std::string name() const override { return "Winograd"; }
private:
    std::vector<double> compute_row_factors(const Matrix &A) const;
    std::vector<double> compute_col_factors(const Matrix &B) const;
};
#endif