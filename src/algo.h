#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "matrix.h"
#include <string>

class Algo {
public:
    virtual ~Algo() = default;
    virtual Matrix multiply(const Matrix &A, const Matrix &B) const = 0;
    virtual std::string name() const = 0;
};

#endif