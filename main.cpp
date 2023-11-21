#include "tiele.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<double>> data_A = {{3, 1, 4},
                                               {2, 3, 6},
                                               {0, 5, 10}};
    auto A = tiele::Matrix(data_A);
    for (int i = 0; i < 1000; ++i) {
        auto qr = tiele::eigen(A);
    }
}