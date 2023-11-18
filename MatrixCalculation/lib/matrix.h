#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <sstream>

namespace tiele {
    class Matrix {
    private:
        std::vector<std::vector<double>> data;
        uint32_t row_size;
        uint32_t col_size;

        void _copy(const Matrix& other);

    public:
        // default constructor
        Matrix() = default;

        // copy constructor
        Matrix(const Matrix& other);

        // constructors
        Matrix(uint32_t rows, uint32_t cols);
        Matrix(std::vector<std::vector<double>> start_data);

        // destructor
        ~Matrix();

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

        // overload assignment operator
        Matrix& operator=(const Matrix& other);

        // overload insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

        // overload plus operator
        // C = A + B
        Matrix operator+(const Matrix& other) const;

        // overload minus operator
        // C = A - B
        Matrix operator-(const Matrix& rhs) const;

        // overload multiplication calculator for Matrix-Matrix multiplication
        // C = A * B
        // D = B * A
        Matrix operator*(const Matrix& rhs) const;

        // overload multiplication calculator for Scalar-Matrix multiplication
        // B = A * c
        Matrix operator*(double rhs_scalar) const;

        // overload multiplication calculator for Scalar-Matrix multiplication
        // B = c * A
        friend Matrix operator*(double lhs_scalar, const Matrix& rhs_matrix);
    };

}

#endif