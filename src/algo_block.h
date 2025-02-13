#ifndef BLOCKED_ALGORITHM_H
#define BLOCKED_ALGORITHM_H

#include "algo.h"

class BlockedAlgo : public Algo {
public:
    explicit BlockedAlgo(size_t block_size) : block_size_(block_size) {}
    Matrix multiply(const Matrix &A, const Matrix &B) const override;
    std::string name() const override { return "Blocked"; }

private:
    size_t block_size_;
};

#endif