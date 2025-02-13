#include <gtest/gtest.h>
#include "algo_naive.h"
#include "algo_block.h"
#include "algo_strassen.h"

class MatMulTest: public ::testing::Test {
    protected:
        void SetUp() override {
            A = {{1, 2}, {3, 4}};
            B = {{5, 6}, {7, 8}};
            expected = {{19, 22}, {43, 50}};
        }
    
        Matrix A, B, expected;
    };

TEST_F(MatMulTest, NaiveMultiply) {
    NaiveAlgo algo;
    Matrix result = algo.multiply(A, B);
    EXPECT_TRUE(are_matrices_equal(result, expected));
}

TEST_F(MatMulTest, BlockedMultiply) {
    BlockedAlgo algo(1);  
    Matrix result = algo.multiply(A, B);
    EXPECT_TRUE(are_matrices_equal(result, expected));
}

TEST_F(MatMulTest, StrassenMultiply) {
    StrassenAlgo algo;
    Matrix result = algo.multiply(A, B);
    EXPECT_TRUE(are_matrices_equal(result, expected));
}