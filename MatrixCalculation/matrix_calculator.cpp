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
            uint32_t pivot_row = i;
            for (uint32_t j = i + 1; j < original.getRowSize(); ++j) {
                if (std::abs(original.getValue(j, i)) > std::abs(original.getValue(pivot_row, i))) {
                    pivot_row = j;
                }
            }

            // Swap rows to make pivot element the largest
            original.swapRows(i, pivot_row);
            identity.swapRows(i, pivot_row);

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

    Matrix reduced_row_echelon(const Matrix& matrix) {
        Matrix rref(matrix);
        uint32_t curr_col = 0;

        for (uint32_t i = 0; i < rref.getRowSize(); ++i) {
            uint32_t pivot_row = rref.findPivotRow(i, curr_col);

            if (rref.getValue(pivot_row, curr_col) != 0) {
                rref.swapRows(i, pivot_row);
                double pivotElement = rref.getValue(i, curr_col);
                for (uint32_t j = i; j < rref.getColSize(); ++j) {
                    rref.setValue(i, j, rref.getValue(i, j) / pivotElement);
                }
                for (uint32_t k = 0; k < rref.getRowSize(); ++k) {
                    if (k != i) {
                        double factor = rref.getValue(k, curr_col);
                        for (uint32_t j = i; j < rref.getColSize(); ++j) {
                            rref.setValue(k, j, rref.getValue(k, j) - factor * rref.getValue(i, j));
                        }
                    }
                }
                curr_col++;
            }
        }

        return rref;
    }

    Matrix row_echelon_form(const Matrix& matrix) {
        Matrix ref = matrix;
        uint32_t curr_col = 0;
        for (uint32_t i = 0; i < ref.getRowSize(); ++i) {
            uint32_t pivotRow = ref.findPivotRow(i, curr_col);

            if (ref.getValue(pivotRow, curr_col) != 0) {
                ref.swapRows(i, pivotRow);
                double pivotElement = ref.getValue(i, curr_col);
                for (uint32_t j = i; j < ref.getColSize(); ++j) {
                    ref.setValue(i, j, ref.getValue(i, j) / pivotElement);
                }

                for (uint32_t k = i + 1; k < ref.getRowSize(); ++k) {
                    double factor = ref.getValue(k, curr_col);
                    for (uint32_t j = i; j < ref.getColSize(); ++j) {
                        ref.setValue(k, j, ref.getValue(k, j) - factor * ref.getValue(i, j));
                    }
                }
                curr_col++;
            }
        }
        return ref;
    }

    uint32_t matrix_rank(const Matrix& matrix) {
        // Make matrix to REF
        Matrix refMatrix = row_echelon_form(matrix);

        // Count number of non-zero rows
        uint32_t rank = 0;
        for (uint32_t i = 0; i < refMatrix.getRowSize(); ++i) {
            bool is_zero_row = true;
            for (uint32_t j = 0; j < refMatrix.getColSize(); ++j) {
                if (refMatrix.getValue(i, j) != 0) {
                    is_zero_row = false;
                    break;
                }
            }
            if (!is_zero_row) ++rank;
        }
        return rank;
    }

    double det(const Matrix& matrix) {
        // Must be a square matrix
        // 1 x 1 matrix return self
        if (matrix.getRowSize() != matrix.getColSize()) {
            std::cerr << "Input is not a square matrix" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        } else if (matrix.getRowSize() == 1) return matrix.getValue(0, 0);

        double determinant = 0;

        for (uint32_t col = 0; col < matrix.getColSize(); ++col) {
            // Calculate the minor matrix det by excluding the current row and column
            Matrix minor_matrix(matrix.getRowSize() - 1, matrix.getColSize() - 1);

            for (uint32_t i = 1; i < matrix.getRowSize(); ++i) {
                for (uint32_t j = 0; j < matrix.getColSize(); ++j) {
                    if (j < col) {
                        minor_matrix.setValue(i - 1, j, matrix.getValue(i, j));
                    } else if (j > col) {
                        minor_matrix.setValue(i - 1, j - 1, matrix.getValue(i, j));
                    }
                }
            }

            // Recursive call to calculate det of rest minor matrix
            double minor_determinant = det(minor_matrix);
            determinant += ((col % 2 == 0) ? 1 : -1) * matrix.getValue(0, col) * minor_determinant;
        }

        return determinant;
    }

    double trace(const Matrix& matrix) {
        if (matrix.getRowSize() != matrix.getColSize()) {
            std::cerr << "Input is not a square matrix" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }
        double trace = 0;
        for (uint32_t i = 0; i < matrix.getRowSize(); ++i) {
            trace += matrix.getValue(i, i);
        }
        return trace;
    }

    double norm(const Matrix& matrix, uint32_t degree) {
        if (degree != 1 && degree != 2 && 
            degree != std::numeric_limits<int>::infinity()) {
            std::cerr << "degree can only be 1, 2 or inf" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }

        double norm = 0.0;

        // for degree 1 it's the max of column sum
        if (degree == 1) {
            for (uint32_t j = 0; j < matrix.getColSize(); ++j) {
                double col_sum = 0;
                for (uint32_t i = 0; i < matrix.getRowSize(); ++i) {
                    col_sum += std::abs(matrix.getValue(i, j));
                }
                norm = std::max(norm, col_sum);
            }
        } else if (degree == 2) {
            // if degree 2 it's Frobenius norm (Subject to change)
            for (uint32_t i = 0; i < matrix.getRowSize(); ++i) {
                for (uint32_t j = 0; j < matrix.getColSize(); ++j) {
                    norm += std::pow(matrix.getValue(i, j), 2);
                }
            }
            norm = std::sqrt(norm);
        } else if (degree == std::numeric_limits<int>::infinity()) {
            // for inf-norm it's max or row sum
            for (uint32_t i = 0; i < matrix.getRowSize(); ++i) {
                double row_sum = 0;
                for (uint32_t j = 0; j < matrix.getColSize(); ++j) {
                    row_sum += std::abs(matrix.getValue(i, j));
                }
                norm = std::max(norm, row_sum);
            }
        }

        return norm;
    }

    double cond(const Matrix& matrix, int degree) {
        if (matrix.getRowSize() != matrix.getColSize()) {
            std::cerr << "Square matrix needed" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }
        double matrix_norm = norm(matrix, degree);

        // Check if the matrix is singular or not
        if (std::abs(det(matrix)) < std::numeric_limits<double>::epsilon()) {
            return std::numeric_limits<double>::infinity();
        }

        // Get inverse matrix norm
        Matrix inv_matrix = inverse(matrix);
        double inv_matrix_norm = norm(inv_matrix, degree);

        // Cond(A) = ||A^-1||*||A||
        double cond = inv_matrix_norm * matrix_norm;
        return cond;
    }

    std::pair<Matrix, Matrix> qrDecomposition(const Matrix& matrix) {
        Matrix A(matrix);
        uint32_t m = matrix.getRowSize();
        uint32_t n = matrix.getColSize();
        Matrix Q(m, n);
        Matrix R(n, n);
        for (uint32_t j = 0; j < n; ++j) {
            Matrix v = A.getColumn(j);
            for (uint32_t i = 0; i < j; ++i) {
                double dot = dotProduct(Q.getColumn(i), A.getColumn(j));
                v = v - dot * Q.getColumn(i);
            }
            double normV = norm(v, 2);
            if (normV < 1e-8) continue;

            // Q
            for (uint32_t i = 0; i < m; ++i) {
                Q.setValue(i, j, v.getValue(i, 0) / normV);
            }

            // R
            for (uint32_t i = j; i < n; ++i) {
                R.setValue(j, i, dotProduct(Q.getColumn(j), A.getColumn(i)));
            }
        }

        return std::make_pair(Q, R);
    }

    double dotProduct(const Matrix& matrix1, const Matrix& matrix2) {
        double result = 0;
        for (uint32_t i = 0; i < matrix1.getRowSize(); ++i) {
            result += matrix1.getValue(i, 0) * matrix2.getValue(i, 0);
        }
        return result;
    }

}


