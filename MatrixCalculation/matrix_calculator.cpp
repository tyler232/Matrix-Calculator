#include "matrix_calculator.h"

Matrix MatrixCalculator::addition(const Matrix& matrix_A, const Matrix& matrix_B) {
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

Matrix MatrixCalculator::subtraction(const Matrix& matrix_A, const Matrix& matrix_B) {
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