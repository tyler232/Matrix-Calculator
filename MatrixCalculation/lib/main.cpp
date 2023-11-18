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

    std::vector<std::vector<double>> data = {{0, 1, 4},
                                             {2, 3, 6},
                                             {0, 5, 7}};
    std::cout << "Here" << std::endl;
    Matrix matrix_A(data);
    std::cout << matrix_A << std::endl;

    return 0;
}