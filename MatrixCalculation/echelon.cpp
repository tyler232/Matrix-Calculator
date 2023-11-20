#include "echelon.h"

namespace tiele {
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
}