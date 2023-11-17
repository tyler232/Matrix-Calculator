#include "matrix.h"

Matrix::Matrix(uint32_t rows, uint32_t cols) : row_size(rows), col_size(cols) {
    for (uint32_t i = 0; i < row_size; ++i) {
        data.push_back(std::vector<double>(col_size, 0));
    }
}

Matrix::Matrix(std::vector<std::vector<double>> start_data) {
    data = start_data;
    row_size = start_data.size();
    col_size = start_data[0].size();
}

uint32_t Matrix::getRowSize() const {
    return row_size;
}

uint32_t Matrix::getColSize() const {
    return col_size;
}

double Matrix::getValue(uint32_t row, uint32_t col) const {
    if (row < row_size && col < col_size) return data[row][col];

    // input argument over the size of matrix or smaller than 0
    std::cerr << "Invalid matrix indices." << std::endl;
    return 0.0;
}

// ReShape Row, if new Row is greater than the original Row append 0 to extra space
// If Row is less than the original row Truncate the extra values
// Don't do anything if user inputted the same size as original
void Matrix::setRowSize(uint32_t new_row_size) {
    if (row_size == new_row_size) return;
    if (new_row_size > row_size) {
        // Append zeros to extra space
        for (uint32_t row = 0; row < new_row_size - row_size; ++row) {
            data.push_back(std::vector<double>(col_size, 0));
        }
    } else {
        // Truncate extra values
        data.resize(new_row_size);
    }
    row_size = new_row_size;
}

// ReShape Column, if new Column is greater than the original Column append 0 to the extra space
// If Column is less than the original row Truncate the extra values
// Don't do anything if user inputted the same size as original
void Matrix::setColSize(uint32_t new_col_size) {
    if (new_col_size == col_size) return;
    if (new_col_size > col_size) {
        for (uint32_t i = 0; i < row_size; ++i) {
            for (uint32_t j = col_size; j < new_col_size; ++j) {
                data[i].push_back(0.0);
            }
        }
    } else {
        for (uint32_t i = 0; i < row_size; ++i) {
            data[i].resize(new_col_size);
        }
    }
    col_size = new_col_size;
}

// Set value in the matrix at desired location 
void Matrix::setValue(uint32_t row, uint32_t col, double value) {
    if (row < row_size && col < col_size) {
        data[row][col] = value;
        return;
    }

    // input argument over the size of matrix or smaller than 0
    std::cerr << "Invalid matrix indices." << std::endl;
}

 void Matrix::print() const {
    for (auto row : data) {
        for (auto value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Rows: " << row_size << std::endl;
    std::cout << "Cols: " << col_size << std::endl;
}

// Get Matrix Transpose
void Matrix::transpose() {
    std::swap(row_size, col_size);
    for (uint32_t i = 0; i < row_size; ++i) {
        for (uint32_t j = i + 1; j < col_size; ++j) {
            std::swap(data[i][j], data[j][i]);
        }
    }
}
