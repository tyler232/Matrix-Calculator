#include "tiele.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<double>> data_A = {{3, 1, 4},
                                               {2, 3, 6},
                                               {0, 5, 10}};
    std::vector<std::vector<double>> data_B = {{7, 1, 6},
                                               {2, 4, 8},
                                               {7, 3, 8}};
    std::vector<std::vector<double>> data_b = {{2},
                                               {4},
                                               {7}};
    std::vector<std::vector<double>> data_a = {{2, -2},
                                               {4, 3}};
    tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
    // complex algorithm, if you are interested please check tiele.h and tiele.cpp with detailed explaination
    std::pair<std::vector<double>, tiele::Matrix> eigen_A = tiele::eigen(A);
    // eigenvalues
    for (double eigenvalue : eigen_A.first) {
        std::cout << eigenvalue << " ";
    }
    std::cout << std::endl;
    // eigenvectors (column)
    std::cout << tiele::eigen(A).second << std::endl;
}