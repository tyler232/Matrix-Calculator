#ifndef MATRIX_CALCULATOR_H
#define MATRIX_CALCULATOR_H

#include "./MatrixImplementation/matrix.h"

class MatrixCalculator {
public:
    // Matrix addition
    static Matrix addition(const Matrix& matrix1, const Matrix& matrix2);

    // Matrix subtraction
    static Matrix subtraction(const Matrix& matrix1, const Matrix& matrix2);

    // Matrix multiplication
    static Matrix multiply(const Matrix& matrix1, const Matrix& matrix2);
};

#endif