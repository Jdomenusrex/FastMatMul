#include <gtest/gtest.h>
#include "matmul.h"

TEST(MatrixMultiplication, NaiveMultiply) {
    Matrix A = { {1, 2}, {3, 4} };
    Matrix B = { {5, 6}, {7, 8} };
    Matrix expected = { {19, 22}, {43, 50} };

    Matrix res_naive = naive_multiply(A, B);
    EXPECT_TRUE(are_matrices_equal(res_naive, expected));
}

TEST(MatrixMultiplication, BlockedMultiply) {
    Matrix A = { {1, 2}, {3, 4} };
    Matrix B = { {5, 6}, {7, 8} };
    Matrix expected = { {19, 22}, {43, 50} };

    Matrix res_blocked = blocked_multiply(A, B, 1);
    EXPECT_TRUE(are_matrices_equal(res_blocked, expected));
}

TEST(MatrixMultiplication, strassen) {
    Matrix A = { {1, 2}, {3, 4} };
    Matrix B = { {5, 6}, {7, 8} };
    Matrix expected = { {19, 22}, {43, 50} };

    Matrix res_strassen = strassen(A, B);
    EXPECT_TRUE(are_matrices_equal(res_strassen, expected));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
