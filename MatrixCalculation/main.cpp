#include "lib/matrix.h"
#include "matrix_calculator.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<double>> data_A = {{0, 1, 4},
                                               {2, 3, 6},
                                               {0, 5, 10}};
    std::vector<std::vector<double>> data_B = {{7, 1, 6, 4},
                                               {2, 4, 8, 3},
                                               {7, 3, 8, -1.3}};
    std::vector<std::vector<double>> data_b = {{2},
                                               {4},
                                               {7}};
    std::vector<std::vector<double>> data_a = {{2, -2},
                                               {4, 3}};
    tiele::Matrix matrix_A(data_A);
    tiele::Matrix matrix_B(data_B);
    tiele::Matrix matrix_b(data_b);
    tiele::Matrix matrix_a(data_a);

    tiele::Matrix matrix_C = tiele::addition(matrix_A, matrix_B);
    std::cout << matrix_C << std::endl;
    std::cout << std::endl;
    tiele::Matrix matrix_D = tiele::subtraction(matrix_A, matrix_B);
    std::cout << matrix_D << std::endl;
    std::cout << std::endl;
    tiele::Matrix matrix_E = tiele::multiplication(matrix_A, matrix_B);
    std::cout << matrix_E << std::endl;
    std::cout << std::endl;
    tiele::Matrix matrix_F = tiele::transpose(matrix_A);
    std::cout << matrix_F << std::endl;
    std::cout << std::endl;
    tiele::Matrix matrix_G = tiele::identity(3);
    std::cout << matrix_G << std::endl;
    std::cout << std::endl;

    tiele::Matrix matrix_H = tiele::inverse(matrix_A);
    std::cout << matrix_H << std::endl;
    std::cout << std::endl;

    tiele::Matrix matrix_I = tiele::solve(matrix_A, matrix_b);
    std::cout << matrix_I << std::endl;
    std::cout << std::endl;

    tiele::Matrix matrix_J = tiele::reduced_row_echelon(matrix_B);
    std::cout << matrix_J << std::endl;
    std::cout << std::endl;

    int r = tiele::matrix_rank(matrix_B);
    std::cout << r << std::endl;
    std::cout << std::endl;

    double d = tiele::det(matrix_a);
    std::cout << d << std::endl;
    std::cout << std::endl;
    return 0;
}