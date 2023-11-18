#ifndef MATRIX_CALCULATOR_H
#define MATRIX_CALCULATOR_H

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

    /// @brief return a identity matrix of given size
    /// @param size 
    /// @return identity matrix
    Matrix identity(uint32_t size);

    /// @brief get the inverse of input matrix
    /// @param matrix 
    /// @return a copy of inverse of original matrix
    Matrix inverse(const Matrix& matrix);

    /// @brief Solve for Matrix (Ax = b solve for x)
    /// @param lhs_matrix (A)
    /// @param rhs_matrix (b)
    /// @return solved matrix (x)
    Matrix solve(const Matrix& lhs_matrix, const Matrix& rhs_matrix);

    /// @brief find Reduced Row Echelon form
    /// @param matrix 
    /// @return RREF of inputted matrix
    Matrix reduced_row_echelon(const Matrix& matrix);

    /// @brief  find Row Echelon form 
    /// @param matrix 
    /// @return REF of inputted matrix
    Matrix row_echelon_form(const Matrix& matrix);

    /// @brief find rank of input matrix
    /// @param matrix 
    /// @return rank
    uint32_t matrix_rank(const Matrix& matrix);

    /// @brief  get the determinant of the matrix inputted using recursion
    /// @param matrix 
    /// @return determinant of matrix
    double det(const Matrix& matrix);


    /// @brief get the trace of matrix (sum of the main diagnol)
    /// @param matrix 
    /// @return trace(sum of the main diagnol)
    double trace(const Matrix& matrix);
}

#endif