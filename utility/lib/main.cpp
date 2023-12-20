#include "src/matrix.h"
#include <iostream>

int main() {
    tiele::Matrix matrix(3, 3);
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
    tiele::Matrix matrix_A(data_1);
    tiele::Matrix matrix_B(data_2);
    std::cout << matrix_A + matrix_B << std::endl;
    std::cout << matrix_A - matrix_B << std::endl;
    std::cout << matrix_A * matrix_B << std::endl;

    double scalar = 2.3;
    std::cout << matrix_A * scalar << std::endl;
    std::cout << scalar * matrix_A << std::endl;

    tiele::Matrix matrix_C = matrix_A;
    std::cout << matrix_C << std::endl;

    tiele::Matrix matrix_D(matrix_C);
    std::cout << matrix_D << std::endl;

    matrix_A.swapRows(0, 2);
    std::cout << matrix_A << std::endl;

    tiele::Matrix vec({3, 2, 5});
    std::cout << vec << std::endl;
    std::cout << matrix_A << std::endl;
    matrix_A.append_column({2, 2, 1});
    std::cout << matrix_A << std::endl;
    return 0;
}