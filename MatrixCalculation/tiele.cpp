#include "tiele.h"

namespace tiele {
    Matrix transpose(const Matrix& matrix) {
        Matrix result(matrix.getColSize(), matrix.getRowSize());

        for (uint32_t i = 0; i < matrix.getRowSize(); ++i) {
            for (uint32_t j = 0; j < matrix.getColSize(); ++j) {
                result.setValue(j, i, matrix.getValue(i, j));
            }
        }

        return result;
    }

    Matrix identity(uint32_t size) {
        Matrix identity(size, size);
        for (uint32_t i = 0; i < size; ++i) {
            identity.setValue(i, i, 1.0);
        }
        return identity;
    }

    Matrix inverse(const Matrix& matrix) {
        if (matrix.getRowSize() != matrix.getColSize()) {
            throw std::invalid_argument("Input Matrix is not a square matrix");
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
            throw std::invalid_argument("Input Matrix is not a square matrix");
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
            throw std::invalid_argument("Input Matrix is not a square matrix");
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
            throw std::invalid_argument("Input degree must be 1, 2 or infinite");
        }
        double norm = 0;
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
            // if degree 2 it's singular norm
            Matrix matrix_T = tiele::transpose(matrix);
            std::vector<double> eigenvals = eigenvalues(matrix_T * matrix);
            if (eigenvals.empty()) {
                throw std::invalid_argument("Matrix is singular");
            }
            // 2-norm is the sqrt of the largest eigenvalue
            for (auto eigenval : eigenvals) eigenval = std::abs(eigenval);
            norm = std::sqrt(*std::max_element(eigenvals.begin(), eigenvals.end()));
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
            throw std::invalid_argument("Input Matrix is not a square matrix");
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
            double normV = norm_frob(v);
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

    std::vector<double> eigenvalues(const Matrix& matrix, uint32_t iterations) {
        uint32_t size = matrix.getRowSize();
        Matrix A(matrix);
        // Apply QR decomposition
        for (uint32_t iter = 0; iter < iterations; ++iter) {
            double shift = A.getValue(size - 1, size - 1);
            Matrix Q, R;
            auto QR = qrDecomposition(A - (shift * identity(size)));
            Q = QR.first;
            R = QR.second;
            A = R * Q + shift * identity(size);
        }

        // extract eigen value from the diagnol matrix we got
        std::vector<double> eigenvalues;
        for (uint32_t i = 0; i < size; ++i) {
            eigenvalues.push_back(A.getValue(i, i));
        }
        return eigenvalues;
    }

    double dotProduct(const Matrix& matrix1, const Matrix& matrix2) {
        double result = 0;
        for (uint32_t i = 0; i < matrix1.getRowSize(); ++i) {
            result += matrix1.getValue(i, 0) * matrix2.getValue(i, 0);
        }
        return result;
    }

    std::vector<Matrix> eigenvectors(const Matrix& matrix, uint32_t iterations) {
        std::vector<double> eig_vals = eigenvalues(matrix, iterations);
        std::vector<Matrix> eig_vecs;

        for (double eig_val : eig_vals) {
            // Shift Matrix (A - lambda * I)
            Matrix shiftedMatrix = matrix - identity(matrix.getRowSize()) * eig_val;

            // Solve for (A - lambda * I) * v = 0 using QR decomposition
            std::pair<Matrix, Matrix> qrResult = qrDecomposition(shiftedMatrix);
            Matrix upperTriangular = qrResult.second;

            // Back-substitution to find v
            Matrix eigenvector(matrix.getRowSize(), 1);
            eigenvector.setValue(matrix.getRowSize() - 1, 0, 1.0);

            for (int i = matrix.getRowSize() - 2; i >= 0; --i) {
                double sum = 0.0;
                for (uint32_t j = i + 1; j < matrix.getRowSize(); ++j) {
                    sum += upperTriangular.getValue(i, j) * eigenvector.getValue(j, 0);
                }
                double value = -sum / upperTriangular.getValue(i, i);
                eigenvector.setValue(i, 0, value);
            }
            eig_vecs.push_back(eigenvector);
        }
        return eig_vecs;
    }
    
    double norm_frob(const Matrix& matrix) {
        double norm = 0;
        for (uint32_t i = 0; i < matrix.getRowSize(); ++i) {
            for (uint32_t j = 0; j < matrix.getColSize(); ++j) {
                    norm += std::pow(matrix.getValue(i, j), 2);
            }
        }
        return std::sqrt(norm);
    }

    std::pair<Matrix, Matrix> luDecomposition(const Matrix& matrix) {
        if (matrix.getRowSize() != matrix.getColSize()) {
            throw std::invalid_argument("Input matrix must be a square matrix");
        }

        uint32_t size = matrix.getRowSize();
        Matrix L(size, size);
        Matrix U = matrix;
        for (uint32_t i = 0; i < size; ++i) {
            L.setValue(i, i, 1.0);
            for (uint32_t j = i + 1; j < size; ++j) {
                double factor = U.getValue(j, i) / U.getValue(i, i);
                L.setValue(j, i, factor);
                for (uint32_t k = i; k < size; ++k) {
                    U.setValue(j, k, U.getValue(j, k) - factor * U.getValue(i, k));
                }
            }
        }
        return {L, U};
    }

    Matrix eigenvectors_asMatrix(const Matrix& matrix, uint32_t iterations) {
        std::vector<double> eig_vals = eigenvalues(matrix, iterations);
        Matrix eig_vecs(matrix.getRowSize(), eig_vals.size());

        for (size_t i = 0; i < eig_vals.size(); ++i) {
            // Shift Matrix (A - lambda * I)
            Matrix shiftedMatrix = matrix - identity(matrix.getRowSize()) * eig_vals[i];

            // Solve for (A - lambda * I) * v = 0 using QR decomposition
            std::pair<Matrix, Matrix> qrResult = qrDecomposition(shiftedMatrix);
            Matrix upperTriangular = qrResult.second;

            // Back-substitution to find v
            Matrix eigenvector(matrix.getRowSize(), 1);
            eigenvector.setValue(matrix.getRowSize() - 1, 0, 1.0);

            for (int j = matrix.getRowSize() - 2; j >= 0; --j) {
                double sum = 0.0;
                for (uint32_t k = j + 1; k < matrix.getRowSize(); ++k) {
                    sum += upperTriangular.getValue(j, k) * eigenvector.getValue(k, 0);
                }
                double value = -sum / upperTriangular.getValue(j, j);
                eigenvector.setValue(j, 0, value);
            }

            // Set the column in eig_vecs matrix
            for (uint32_t row = 0; row < matrix.getRowSize(); ++row) {
                eig_vecs.setValue(row, i, eigenvector.getValue(row, 0));
            }
        }

        return eig_vecs;
    }

    std::vector<Matrix> eigenvectors_normalized(const Matrix& matrix, uint32_t iterations) {
        std::vector<double> eig_vals = eigenvalues(matrix, iterations);
        std::vector<Matrix> eig_vecs;

        for (double eig_val : eig_vals) {
            // Shift Matrix (A - lambda * I)
            Matrix shiftedMatrix = matrix - identity(matrix.getRowSize()) * eig_val;

            // Solve for (A - lambda * I) * v = 0 using QR decomposition
            std::pair<Matrix, Matrix> qrResult = qrDecomposition(shiftedMatrix);
            Matrix upperTriangular = qrResult.second;

            // Back-substitution to find v
            Matrix eigenvector(matrix.getRowSize(), 1);
            eigenvector.setValue(matrix.getRowSize() - 1, 0, 1.0);

            for (int i = matrix.getRowSize() - 2; i >= 0; --i) {
                double sum = 0.0;
                for (uint32_t j = i + 1; j < matrix.getRowSize(); ++j) {
                    sum += upperTriangular.getValue(i, j) * eigenvector.getValue(j, 0);
                }
                double value = -sum / upperTriangular.getValue(i, i);
                eigenvector.setValue(i, 0, value);
            }
            eig_vecs.push_back(eigenvector / norm(eigenvector, 2));
        }
        return eig_vecs;
    }

    Matrix eigenvectors_normalized_asMatrix(const Matrix& matrix, uint32_t iterations) {
        std::vector<double> eig_vals = eigenvalues(matrix, iterations);
        Matrix eig_vecs(matrix.getRowSize(), eig_vals.size());

        for (size_t i = 0; i < eig_vals.size(); ++i) {
            // Shift Matrix (A - lambda * I)
            Matrix shiftedMatrix = matrix - identity(matrix.getRowSize()) * eig_vals[i];

            // Solve for (A - lambda * I) * v = 0 using QR decomposition
            std::pair<Matrix, Matrix> qrResult = qrDecomposition(shiftedMatrix);
            Matrix upperTriangular = qrResult.second;

            // Back-substitution to find v
            Matrix eigenvector(matrix.getRowSize(), 1);
            eigenvector.setValue(matrix.getRowSize() - 1, 0, 1.0);

            for (int j = matrix.getRowSize() - 2; j >= 0; --j) {
                double sum = 0.0;
                for (uint32_t k = j + 1; k < matrix.getRowSize(); ++k) {
                    sum += upperTriangular.getValue(j, k) * eigenvector.getValue(k, 0);
                }
                double value = -sum / upperTriangular.getValue(j, j);
                eigenvector.setValue(j, 0, value);
            }

            // Set the column in eig_vecs matrix
            for (uint32_t row = 0; row < matrix.getRowSize(); ++row) {
                eig_vecs.setValue(row, i, eigenvector.getValue(row, 0) / norm(eigenvector, 2));
            }
        }

        return eig_vecs;
    }

    std::pair<std::vector<double>, Matrix> eigen(const Matrix& matrix, uint32_t iterations) {
        return std::make_pair(eigenvalues(matrix, iterations), 
                             eigenvectors_normalized_asMatrix(matrix, iterations));
    }

    std::vector<Matrix> svd(const Matrix& matrix) {
        Matrix A = matrix;

        Matrix AAT = A * tiele::transpose(A);
        Matrix ATA = tiele::transpose(A) * A;

        // U = A * At
        // V = At * A
        Matrix U = eigenvectors_normalized_asMatrix(AAT);
        Matrix V = eigenvectors_normalized_asMatrix(ATA);

        // A = U * S * Vt
        // Ut * A = S * Vt
        // Ut * A * V = S
        Matrix S = tiele::transpose(U) * A * V;

        // round of errors
        for (uint32_t i = 0 ; i < S.getRowSize(); ++i) {
            for (uint32_t j = 0; j < S.getColSize(); ++j) {
                if (S.getValue(i, j) < 1e-8) S.setValue(i, j, 0);
            }
        }
        return {U, S, V};
    }
}


