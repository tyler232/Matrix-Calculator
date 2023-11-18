#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <sstream>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    uint32_t row_size;
    uint32_t col_size;

public:
    // default constructor
    Matrix() = default;

    // constructors
    Matrix(uint32_t rows, uint32_t cols);
    Matrix(std::vector<std::vector<double>> start_data);

    // Getters
    uint32_t getRowSize() const;

    uint32_t getColSize() const;

    double getValue(uint32_t row, uint32_t col) const;

    // Setters
    void setRowSize(uint32_t new_row_size);
    void setColSize(uint32_t new_col_size);
    void setValue(uint32_t row, uint32_t col, double value);

    void transpose();

    // to_string
    std::string to_string() const;

    // overload insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};
#endif