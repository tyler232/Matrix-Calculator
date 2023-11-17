#include "matrix.h"
#include <iostream>
int main() {
    Matrix matrix(3, 3);
    matrix.setValue(2, 1, 4);
    matrix.setValue(0, 0, 2);
    matrix.print();
    std::cout << matrix.getValue(2, 1) << std::endl;

    matrix.transpose();
    matrix.print();

    matrix.setColSize(5);
    matrix.print();

    matrix.setColSize(2);
    matrix.print();

    std::vector<std::vector<double>> data = {{0, 1, 4},
                                             {2, 3, 6},
                                             {0, 5, 7}};
    std::cout << "Here" << std::endl;
    Matrix matrix_A(data);
    matrix_A.print();

    return 0;
}