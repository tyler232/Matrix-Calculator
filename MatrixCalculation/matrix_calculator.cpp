#include "matrix_calculator.h"

namespace tiele {
    Matrix addition(const Matrix& matrix_A, const Matrix& matrix_B) {
        if (matrix_A.getRowSize() != matrix_B.getRowSize() || 
            matrix_A.getColSize() != matrix_B.getColSize()) {
            std::cerr << "Two matrix have different dimension" << std::endl;
            return Matrix();
        }

        uint32_t rows = matrix_A.getRowSize();
        uint32_t cols = matrix_A.getColSize();
        Matrix result(rows, cols);

        for (uint32_t i = 0; i < rows; ++i) {
            for (uint32_t j = 0; j < cols; ++j) {
                result.setValue(i, j, matrix_A.getValue(i, j) + matrix_B.getValue(i, j));
            }
        }
        return result;
    }

    Matrix subtraction(const Matrix& matrix_A, const Matrix& matrix_B) {
        if (matrix_A.getRowSize() != matrix_B.getRowSize() || 
            matrix_A.getColSize() != matrix_B.getColSize()) {
            std::cerr << "Two matrix have different dimension" << std::endl;
            return Matrix();
        }
        
        uint32_t rows = matrix_A.getRowSize();
        uint32_t cols = matrix_A.getColSize();
        Matrix result(rows, cols);

        for (uint32_t i = 0; i < rows; ++i) {
            for (uint32_t j = 0; j < cols; ++j) {
                result.setValue(i, j, matrix_A.getValue(i, j) - matrix_B.getValue(i, j));
            }
        }
        return result;
    }

    Matrix multiplication(const Matrix& matrix_A, const Matrix& matrix_B) {
        if (matrix_A.getColSize() != matrix_B.getRowSize()) {
            std::cerr << "Incorrect Dimension for Multiplication" << std::endl;
            return Matrix();
        }
        uint32_t rows_a = matrix_A.getRowSize();
        uint32_t cols_a = matrix_A.getColSize();
        uint32_t cols_b = matrix_B.getColSize();

        // (a x b) * (b x c) = (a x c)
        Matrix result(rows_a, cols_b);

        for (uint32_t i = 0; i < rows_a; ++i) {
            for (uint32_t j = 0; j < cols_b; ++j) {
                double sum = 0;
                for (uint32_t k = 0; k < cols_a; ++k) {
                    sum += matrix_A.getValue(i, k) * matrix_B.getValue(k, j);
                }
                result.setValue(i, j, sum);
            }
        }

        return result;
    }

    Matrix transpose(const Matrix& matrix) {
        Matrix result(matrix.getColSize(), matrix.getRowSize());

        for (uint32_t i = 0; i < matrix.getRowSize(); ++i) {
            for (uint32_t j = 0; j < matrix.getColSize(); ++j) {
                result.setValue(j, i, matrix.getValue(i, j));
            }
        }

        return result;
    }

    Matrix identity(u_int32_t size) {
        Matrix identity(size, size);
        for (uint32_t i = 0; i < size; ++i) {
            identity.setValue(i, i, 1.0);
        }
        return identity;
    }

    Matrix inverse(const Matrix& matrix) {
        if (matrix.getRowSize() != matrix.getColSize()) {
            std::cerr << "Input is not a square matrix" << std::endl;
            return Matrix();
        }

        // Copy original matrix into original
        Matrix original = matrix;

        // Identity matrix
        Matrix identity = tiele::identity(matrix.getRowSize());

        // Apply Gaussian elimination with partial pivoting
        for (uint32_t i = 0; i < original.getRowSize(); ++i) {
            // Find pivot row
            uint32_t pivotRow = i;
            for (uint32_t j = i + 1; j < original.getRowSize(); ++j) {
                if (std::abs(original.getValue(j, i)) > std::abs(original.getValue(pivotRow, i))) {
                    pivotRow = j;
                }
            }

            // Swap rows to make pivot element the largest
            original.swapRows(i, pivotRow);
            identity.swapRows(i, pivotRow);

            // Make original Matrix an identity matrix, first make diagnol to 1
            double pivot = original.getValue(i, i);
            for (uint32_t j = 0; j < original.getColSize(); ++j) {
                original.setValue(i, j, original.getValue(i, j) / pivot);
                identity.setValue(i, j, identity.getValue(i, j) / pivot);
            }

            // Next eliminate non-zero elements in the column
            for (uint32_t j = 0; j < original.getRowSize(); ++j) {
                if (j != i) {
                    double factor = original.getValue(j, i);
                    for (uint32_t k = 0; k < original.getColSize(); ++k) {
                        original.setValue(j, k, original.getValue(j, k) - factor * original.getValue(i, k));
                        identity.setValue(j, k, identity.getValue(j, k) - factor * identity.getValue(i, k));
                    }
                }
            }
        }
        return identity;
    }

    Matrix solve(const Matrix& lhs_matrix, const Matrix& rhs_matrix) {
        return (inverse(lhs_matrix) * rhs_matrix);
    }
}

