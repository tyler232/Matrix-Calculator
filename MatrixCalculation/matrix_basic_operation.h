#ifndef MATRIX_BASIC_OPERATION_H
#define MATRIX_BASIC_OPERATION_H

#include "lib/matrix.h"
#include <iostream>
#include <vector>
#include <limits>

namespace tiele {
    /// @brief add two matricies
    /// @param matrix1 
    /// @param matrix2 
    /// @return result of addition
    Matrix addition(const Matrix& matrix1, const Matrix& matrix2);

    /// @brief subtract two matricies
    /// @param matrix1 
    /// @param matrix2 
    /// @return result of subtraction
    Matrix subtraction(const Matrix& matrix1, const Matrix& matrix2);

    /// @brief multiply two matricies
    /// @param matrix1 
    /// @param matrix2 
    /// @return result of multiplication
    Matrix multiplication(const Matrix& matrix1, const Matrix& matrix2);
}

#endif

