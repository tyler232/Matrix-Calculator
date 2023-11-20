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
    
    std::cout << tiele::svd(A)[0] << std::endl; // U
    std::cout << tiele::svd(A)[1] << std::endl; // S
    std::cout << tiele::svd(A)[2] << std::endl; // V

    tiele::Matrix B({{2, 4, -1},
                    {3, -2, 7.5},
                    {9, 5, 1}});
    return 0;
}