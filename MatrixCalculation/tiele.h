#ifndef TIELE_H
#define TIELE_H

#include "lib/matrix.h"
#include "matrix_basic_operation.h"
#include "matrix_basic_type.h"

#include <iostream>
#include <vector>
#include <limits>

namespace tiele {
    /// @brief transpose a matrix and return a copy of it
    /// @param matrix 
    /// @return transpose of a matrix
    Matrix transpose(const Matrix& matrix);

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

    /// @brief get the norm of matrix (1, 2 or infinity) degree avalible
    /// @param matrix 
    /// @param degree degree of norm, enter 1, 2 or infinity
    /// @return matrix norm with given degree
    double norm(const Matrix& matrix, uint32_t degree);

    /// @brief get the condition of matrix(1, 2 or infinity) degree avalible
    /// @param matrix 
    /// @param degree degree of norm, enter 1, 2 or infinity
    /// @return matrix norm with given degree
    double cond(const Matrix& matrix, int degree);

    /// @brief get the QR decomposition of matrix
    /// @param matrix 
    /// @return matrix Q in first of the pair, matrix R in second of the pair
    std::pair<Matrix, Matrix> qrDecomposition(const Matrix& matrix);

    /// @brief get the eigenvalue of input matrix
    /// @param matrix 
    /// @param iterations default set at 1000, more iteration = more precision
    // but slower runtime, it will mostly converge before 1000, but user have
    // the freedom to adjust convergence
    /// @return vector that contains all the eigenvalue
    std::vector<double> eigenvalues(const Matrix& matrix, uint32_t iterations=1e3);

    /// @brief get the eigenvector of input matrix
    /// @param matrix 
    /// @param iterations default set at 1000, more iteration = more precision
    // but slower runtime, it will mostly converge before 1000, but user have
    // the freedom to adjust convergence
    /// @return vector that contains all the eigenvector
    std::vector<Matrix> eigenvectors(const Matrix& matrix, uint32_t iterations=1e3);

    /// @brief Get the Frobenius norm
    /// @param matrix 
    /// @return Frobenius norm
    double norm_frob(const Matrix& matrix);

    /// @brief inner product of 2 vectors
    /// @param matrix1 v1
    /// @param matrix2 v2
    /// @return dot product of v1 and v2
    double inner(const Matrix& matrix1, const Matrix& matrix2);
    
    std::pair<Matrix, Matrix> luDecomposition(const Matrix& matrix);

    Matrix eigenvectors_asMatrix(const Matrix& matrix, uint32_t iterations=1e3);

    // Matrix eigen(const Matrix& matrix, uint32_t iterations=1e3);

    std::vector<Matrix> eigenvectors_normalized(const Matrix& matrix, uint32_t iterations=1e3);

    Matrix eigenvectors_normalized_asMatrix(const Matrix& matrix, uint32_t iterations=1e3);

    std::pair<std::vector<double>, Matrix> eigen(const Matrix& matrix, uint32_t iterations = 1e3);

    std::vector<Matrix> svd(const Matrix& matrix);

    Matrix outer(const Matrix& vector1, const Matrix& vector2);
}

#endif