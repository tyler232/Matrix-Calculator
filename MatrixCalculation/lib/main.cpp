#include "matrix.h"
#include <iostream>
int main() {
    Matrix matrix(3, 3);
    matrix.setValue(2, 1, 4);
    matrix.setValue(0, 0, 2);
    std::cout << matrix << std::endl;
    std::cout << matrix.getValue(2, 1) << std::endl;

    matrix.transpose();
    std::cout << matrix << std::endl;

    matrix.setColSize(5);
    std::cout << matrix << std::endl;

    matrix.setColSize(2);
    std::cout << matrix << std::endl;

    std::vector<std::vector<double>> data_1 = {{0, 1, 4},
                                             {2, 3, 6},
                                             {0, 5, 7}};
    std::vector<std::vector<double>> data_2 = {{3, 4, 2},
                                             {6, 2, 3},
                                             {2, 7, 4}};
    Matrix matrix_A(data_1);
    Matrix matrix_B(data_2);
    std::cout << matrix_A + matrix_B << std::endl;
    std::cout << matrix_A - matrix_B << std::endl;
    std::cout << matrix_A * matrix_B << std::endl;

    double scalar = 2.3;
    std::cout << matrix_A * scalar << std::endl;
    std::cout << scalar * matrix_A << std::endl;
    return 0;
}