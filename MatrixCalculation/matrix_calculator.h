#ifndef MATRIX_CALCULATOR_H
#define MATRIX_CALCULATOR_H

#include "lib/matrix.h"
#include <iostream>
#include <vector>

namespace tiele {
    // Matrix addition
    Matrix addition(const Matrix& matrix1, const Matrix& matrix2);

    // Matrix subtraction
    Matrix subtraction(const Matrix& matrix1, const Matrix& matrix2);

    // Matrix multiplication
    Matrix multiplication(const Matrix& matrix1, const Matrix& matrix2);

}

#endif