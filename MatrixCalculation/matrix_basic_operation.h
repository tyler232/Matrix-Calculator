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

    /// @brief transpose a matrix and return a copy of it
    /// @param matrix 
    /// @return transpose of a matrix
    Matrix transpose(const Matrix& matrix);

    /// @brief inner product of 2 vectors
    /// @param matrix1 v1
    /// @param matrix2 v2
    /// @return dot product of v1 and v2
    double inner(const Matrix& matrix1, const Matrix& matrix2);

    /// @brief outer product of 2 vectors
    /// @param vector1 v1
    /// @param vector2 v2
    /// @return outer product of v1 and v2
    Matrix outer(const Matrix& vector1, const Matrix& vector2);
}

#endif

