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

    tiele::Matrix v1({1, 3, 7});
    v1 = tiele::transpose(v1);
    tiele::Matrix v2({6, 5, 9});
    v2 = tiele::transpose(v2);
    std::cout << "Inner Product" << std::endl;
    std::cout << tiele::inner(v1, v2) << std::endl;
    std::cout << "Outer Product" << std::endl;
    std::cout << tiele::outer(v1, v2) << std::endl;
    return 0;
}