#include "matrix.h"
namespace tiele {
    Matrix::Matrix(uint32_t rows, uint32_t cols) : row_size(rows), col_size(cols) {
        for (uint32_t i = 0; i < row_size; ++i) {
            data.push_back(std::vector<double>(col_size, 0));
        }
    }

    Matrix::Matrix(const Matrix& other) {
        _copy(other);
    }

    Matrix::~Matrix() {
    }

    Matrix::Matrix(std::vector<std::vector<double>> start_data) {
        data = start_data;
        row_size = start_data.size();
        col_size = start_data[0].size();
    }

    Matrix::Matrix(std::vector<double> start_data) {
        data = {start_data};
        row_size = 1;
        col_size = start_data.size();
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
        throw std::invalid_argument("getValue() : Invalid matrix indices.");
        return 0;
    }

    std::vector<std::vector<double>> Matrix::getData() const {
        return data;
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
        throw std::invalid_argument("setValue() : Invalid matrix indices.");
    }

    std::string Matrix::to_string() const {
        std::ostringstream oss;
        oss << "[";
        for (uint32_t i = 0; i < data.size(); ++i) {
            oss << "[";
            auto row = data[i];
            for (uint32_t ii = 0; ii < row.size(); ++ii) {
                if (ii != row.size() - 1) {
                    oss << row[ii] << ",\t";
                } else {
                    oss << row[ii] << "]";
                }
            }
            if (i != row.size() - 1) oss << std::endl;
        }
        oss << "]";
        oss << std::endl;
        oss << "Rows: " << row_size << std::endl;
        oss << "Cols: " << col_size << std::endl;
        return oss.str();
    }

    void Matrix::append_column(const std::vector<double>& append_col) {
        if (append_col.size() != row_size) {
            throw std::invalid_argument("Column size invalid");
        }
        for (uint32_t i = 0; i < row_size; ++i) {
            data[i].push_back(append_col[i]);
        }
        col_size++;
    }


    Matrix& Matrix::operator=(const Matrix& other) {
        if (this != &other) {
            _copy(other);
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        os << matrix.to_string();
        return os;
    }

    // Get Matrix Transpose (Self)
    void Matrix::transpose() {
        std::swap(row_size, col_size);
        for (uint32_t i = 0; i < row_size; ++i) {
            for (uint32_t j = i + 1; j < col_size; ++j) {
                std::swap(data[i][j], data[j][i]);
            }
        }
    }

    Matrix Matrix::operator+(const Matrix& other) const {
        if (row_size != other.row_size || col_size != other.col_size) {
            std::cerr << "Two matrix have different dimension" << std::endl;
            return Matrix();
        }

        Matrix result(row_size, col_size);

        for (uint32_t i = 0; i < row_size; ++i) {
            for (uint32_t j = 0; j < col_size; ++j) {
                result.setValue(i, j, getValue(i, j) + other.getValue(i, j));
            }
        }
        return result;
    }

    Matrix Matrix::operator-(const Matrix& rhs) const {
        if (row_size != rhs.row_size || col_size != rhs.col_size) {
            std::cerr << "Two matrix have different dimension" << std::endl;
            return Matrix();
        }

        Matrix result(row_size, col_size);

        for (uint32_t i = 0; i < row_size; ++i) {
            for (uint32_t j = 0; j < col_size; ++j) {
                result.setValue(i, j, getValue(i, j) - rhs.getValue(i, j));
            }
        }
        return result;
    }

    // overload multiplication calculator for Matrix-Matrix multiplication
    Matrix Matrix::operator*(const Matrix& rhs) const {
        if (col_size != rhs.row_size) {
            std::cerr << "Incorrect Dimension for Multiplication" << std::endl;
            return Matrix();
        }
            
        // (a x b) * (b x c) = (a x c)
        Matrix result(row_size, rhs.col_size);

        for (uint32_t i = 0; i < row_size; ++i) {
            for (uint32_t j = 0; j < rhs.col_size; ++j) {
                double sum = 0;
                for (uint32_t k = 0; k < col_size; ++k) {
                    sum += getValue(i, k) * rhs.getValue(k, j);
                }
                result.setValue(i, j, sum);
            }
        }

        return result;
    }

    Matrix Matrix::operator*(double rhs_scalar) const {
        Matrix result(row_size, col_size);

        for (uint32_t i = 0; i < row_size; ++i) {
            for (uint32_t j = 0; j < col_size; ++j) {
                result.setValue(i, j, getValue(i, j) * rhs_scalar);
            }
        }

        return result;
    }

    Matrix operator*(double lhs_scalar, const Matrix& rhs_matrix) {
        Matrix result(rhs_matrix.getRowSize(), rhs_matrix.getColSize());

        for (uint32_t i = 0; i < rhs_matrix.getRowSize(); ++i) {
            for (uint32_t j = 0; j < rhs_matrix.getColSize(); ++j) {
                result.setValue(i, j, lhs_scalar * rhs_matrix.getValue(i, j));
            }
        }

        return result;
    }

    Matrix Matrix::operator/(double rhs_scalar) const {
        Matrix result(row_size, col_size);
        for (uint32_t i = 0; i < row_size; ++i) {
            for (uint32_t j = 0; j < col_size; ++j) {
                result.setValue(i, j, getValue(i, j) / rhs_scalar);
            }
        }
        return result;
    }

    void Matrix::swapRows(uint32_t row1, uint32_t row2) {
        if (row1 == row2) return;
        else if (row1 < row_size && row2 < row_size) {
            std::swap(data[row1], data[row2]);
            return;
        }
        std::cerr << "Invalid row indices for swap." << std::endl;
    }

    void Matrix::_copy(const Matrix& other) {
        row_size = other.row_size;
        col_size = other.col_size;
        data = other.data;
    }

    uint32_t Matrix::findPivotRow(uint32_t curr_row, uint32_t col) {
        uint32_t pivot_row = curr_row;
        for (uint32_t j = curr_row + 1; j < row_size; ++j) {
            if (std::abs(data[j][col]) > std::abs(data[pivot_row][col])) {
                pivot_row = j;
            }
        }
        return pivot_row;
    }

    Matrix Matrix::getColumn(uint32_t col) const {
        Matrix result(row_size, 1);
        for (uint32_t i = 0; i < row_size; ++i) {
            result.setValue(i, 0, data[i][col]);
        }
        return result;
    }
}