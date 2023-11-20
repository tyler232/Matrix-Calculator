#ifndef TIELE_H
#define TIELE_H

#include "lib/matrix.h"
#include "matrix_basic_operation.h"
#include "matrix_basic_type.h"
#include "echelon.h"

#include <iostream>
#include <vector>
#include <limits>

namespace tiele {
    /// @brief get the inverse of input matrix
    /// @param matrix 
    /// @return a copy of inverse of original matrix
    Matrix inverse(const Matrix& matrix);

    /// @brief Solve for Matrix (Ax = b solve for x)
    /// @param lhs_matrix (A)
    /// @param rhs_matrix (b)
    /// @return solved matrix (x)
    Matrix solve(const Matrix& lhs_matrix, const Matrix& rhs_matrix);

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
    double norm(const Matrix& matrix, uint32_t degree=2);

    /// @brief get the condition of matrix(1, 2 or infinity) degree avalible
    /// @param matrix 
    /// @param degree degree of norm, enter 1, 2 or infinity
    /// @return matrix norm with given degree
    double cond(const Matrix& matrix, uint32_t degree=2);

    /// @brief get the QR decomposition of matrix
    /// @param matrix 
    /// @return matrix Q in first of the pair, matrix R in second of the pair
    std::pair<Matrix, Matrix> qrDecomposition(const Matrix& matrix);
    
    /// @brief get the LU decomposition of matrix
    /// @param matrix 
    /// @return matrix L in first of the pair, matrix U in second of the pair
    std::pair<Matrix, Matrix> luDecomposition(const Matrix& matrix);

    /// @brief get the Singular Value Decomposition of Matrix
    /// @param matrix 
    /// @return U at vector[0], S at vector[1], V at vector[2]
    std::vector<Matrix> svd(const Matrix& matrix);

    /// @brief get the eigenvalue of input matrix
    /// @param matrix 
    /// @param iterations default set at 1000, more iteration = more precision
    // but slower runtime, it will mostly converge before 1000, but user have
    // the freedom to adjust convergence
    /// @return vector that contains all eigenvalues
    std::vector<double> eigenvalues(const Matrix& matrix, uint32_t iterations=1e3);

    /// @brief get the eigenvector of input matrix
    /// @param matrix 
    /// @param iterations default set at 1000, more iteration = more precision
    // but slower runtime, it will mostly converge before 1000, but user have
    // the freedom to adjust convergence
    /// @return vector that contains all eigenvectors
    std::vector<Matrix> eigenvectors(const Matrix& matrix, uint32_t iterations=1e3);

    /// @brief get the normalized eigenvector, normalize using L2 norm
    /// @param matrix 
    /// @param iterations default set at 1000, more iteration = more precision
    // but slower runtime, it will mostly converge before 1000, but user have
    // the freedom to adjust convergence
    /// @return vector that contains all normalized eigenvectors
    std::vector<Matrix> eigenvectors_normalized(const Matrix& matrix, uint32_t iterations=1e3);

    /// @brief get the eigenvector of input matrix as matrix type
    /// @param matrix 
    /// @param iterations default set at 1000, more iteration = more precision
    // but slower runtime, it will mostly converge before 1000, but user have
    // the freedom to adjust convergence
    /// @return matrix of eigenvectors
    Matrix eigenvectors_asMatrix(const Matrix& matrix, uint32_t iterations=1e3);

    /// @brief get normalized eigenvectors of input matrix as matrix type
    /// @param matrix 
    /// @param iterations default set at 1000, more iteration = more precision
    // but slower runtime, it will mostly converge before 1000, but user have
    // the freedom to adjust convergence
    /// @return matrix of normalized eigenvectors
    Matrix eigenvectors_normalized_asMatrix(const Matrix& matrix, uint32_t iterations=1e3);

    /// @brief get eigenvalue and eigenvector of the matrix
    /// @param matrix 
    /// @param iterations default set at 1000, more iteration = more precision
    // but slower runtime, it will mostly converge before 1000, but user have
    // the freedom to adjust convergence
    /// @return pair of vector and Marix, first of the pair is vector of all the eigen
    // values, second of the pair is the Matrix type of normalized eigenvectors
    std::pair<std::vector<double>, Matrix> eigen(const Matrix& matrix, uint32_t iterations = 1e3);

    /// @brief Get the Frobenius norm
    /// @param matrix 
    /// @return Frobenius norm
    double norm_frob(const Matrix& matrix);
}

#endif