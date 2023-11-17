#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    uint32_t row_size;
    uint32_t col_size;

public:
    // default constructor
    Matrix() = default;

    // constructor
    Matrix(uint32_t rows, uint32_t cols);

    // Getters
    uint32_t getRowSize() const;

    uint32_t getColSize() const;

    double getValue(uint32_t row, uint32_t col) const;

    // Setters
    void setRowSize(uint32_t new_row_size);
    void setColSize(uint32_t new_col_size);
    void setValue(uint32_t row, uint32_t col, double value);

    // Printer
    void print() const;

    void transpose();
};
#endif