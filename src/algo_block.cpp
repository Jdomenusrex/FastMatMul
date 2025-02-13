#include "algo_block.h"

Matrix BlockedAlgo::multiply(const Matrix &A, const Matrix &B) const {
    size_t n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (size_t i0 = 0; i0 < n; i0 += block_size_)
        for (size_t j0 = 0; j0 < n; j0 += block_size_)
            for (size_t k0 = 0; k0 < n; k0 += block_size_)
                for (size_t i = i0; i < std::min(i0 + block_size_, n); ++i)
                    for (size_t k = k0; k < std::min(k0 + block_size_, n); ++k)
                        for (size_t j = j0; j < std::min(j0 + block_size_, n); ++j)
                            C[i][j] += A[i][k] * B[k][j];
    return C;
}
