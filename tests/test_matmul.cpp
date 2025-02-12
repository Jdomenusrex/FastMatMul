#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/matmul.h"

TEST_CASE("2x2 matrix multiplication", "[matmul]") {
    Matrix A = { {1, 2}, {3, 4} };
    Matrix B = { {5, 6}, {7, 8} };
    Matrix expected = { {19, 22}, {43, 50} };

    Matrix res_naive = naive_multiply(A, B);
    Matrix res_blocked = blocked_multiply(A, B, 1); 

    REQUIRE(are_matrices_equal(res_naive, expected));
    REQUIRE(are_matrices_equal(res_blocked, expected));
}