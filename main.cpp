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
    tiele::Matrix B({{2, 4, -1},
                    {3, -2, 7.5},
                    {9, 5, 1}});
    double val = A.getValue(2, 1);
    std::cout << val << std::endl;
    A.setValue(2, 1, -20);
    val = A.getValue(2, 1);
    std::cout << val << std::endl;
    return 0;
}