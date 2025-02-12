#include <bits/stdc++.h>

using namespace std;

array<array<int, 2>, 2> strassen(array<array<int, 2>, 2> a, array<array<int, 2>, 2> b) {
    int M1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    int M2 = (a[1][0] + a[1][1]) * b[0][0];
    int M3 = a[0][0] * (b[0][1] - b[1][1]);
    int M4 = a[1][1] * (b[1][0] - b[0][0]);
    int M5 = (a[0][0] + a[0][1]) * b[1][1];
    int M6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    int M7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    return {{
    {M1 + M4 - M5 + M7, M3 + M5},
    {M2 + M4, M1 + M3 - M2 + M6}
    }};
}

int main() {
    array<array<int, 2>, 2> A = {{{1, 2}, {3, 4}}};
    array<array<int, 2>, 2> B = {{{5, 6}, {7, 8}}};

    auto C = strassen(A, B);

    // Print result
    for (const auto& row : C) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
