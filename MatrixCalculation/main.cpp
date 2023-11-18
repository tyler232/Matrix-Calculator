#include "lib/matrix.h"
#include "matrix_calculator.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<double>> data_A = {{0, 1, 4},
                                               {2, 3, 6},
                                               {0, 5, 10}};
    std::vector<std::vector<double>> data_B = {{7, 1, 6},
                                               {2, 4, 8},
                                               {7, 3, 8}};
    tiele::Matrix matrix_A(data_A);
    tiele::Matrix matrix_B(data_B);

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
    return 0;
}