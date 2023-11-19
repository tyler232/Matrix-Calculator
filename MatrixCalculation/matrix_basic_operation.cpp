#include "matrix_basic_operation.h"

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
}