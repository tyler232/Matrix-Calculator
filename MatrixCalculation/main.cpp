#include "lib/matrix.h"
#include "matrix_calculator.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<double>> data_A = {{0, 1, 4},
                                               {2, 3, 6},
                                               {0, 5, 7}};
    std::vector<std::vector<double>> data_B = {{3, 1, 6},
                                               {2, 4, 8},
                                               {7, 3, 8}};
    Matrix matrix_A(data_A);
    Matrix matrix_B(data_B);

    MatrixCalculator calc;
    Matrix matrix_C = calc.addition(matrix_A, matrix_B);
    matrix_C.print();
    Matrix matrix_D = calc.subtraction(matrix_A, matrix_B);
    matrix_D.print();
    return 0;
}