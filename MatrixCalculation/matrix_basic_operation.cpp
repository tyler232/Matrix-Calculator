#include "matrix_basic_operation.h"

namespace tiele {
    Matrix addition(const Matrix& matrix_A, const Matrix& matrix_B) {
        if (matrix_A.getRowSize() != matrix_B.getRowSize() || 
            matrix_A.getColSize() != matrix_B.getColSize()) {
            throw std::invalid_argument("addition(): Incorrect Dimension");
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
            throw std::invalid_argument("subtraction(): Incorrect Dimension");
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
            throw std::invalid_argument("multiplication(): Incorrect Dimension");
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

    double inner(const Matrix& vector1, const Matrix& vector2) {
        if (vector1.getColSize() != 1 || vector2.getColSize() != 1) {
            throw std::invalid_argument("inner(): Invalid Column Size");
        } else if (vector1.getRowSize() != vector2.getRowSize()) {
            throw std::invalid_argument("inner(): Dimension not match");
        }

        double result = 0;
        for (uint32_t i = 0; i < vector1.getRowSize(); ++i) {
            result += vector1.getValue(i, 0) * vector2.getValue(i, 0);
        }
        return result;
    }

    Matrix outer(const Matrix& vector1, const Matrix& vector2) {
        if (vector1.getColSize() != 1 || vector2.getColSize() != 1) {
            throw std::invalid_argument("outer(): Invalid Column Size");
        }

        uint32_t size1 = vector1.getRowSize();
        uint32_t size2 = vector2.getRowSize();

        Matrix result(size1, size2);

        for (uint32_t i = 0; i < size1; ++i) {
            for (uint32_t j = 0; j < size2; ++j) {
                result.setValue(i, j, vector1.getValue(i, 0) * vector2.getValue(j, 0));
            }
        }
        return result;
    }
}