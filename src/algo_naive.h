#ifndef NAIVE_ALGORITHM_H
#define NAIVE_ALGORITHM_H

#include "algo.h"

class NaiveAlgo : public Algo {
public:
    Matrix multiply(const Matrix &A, const Matrix &B) const override;
    std::string name() const override { return "Naive"; }
};

#endif