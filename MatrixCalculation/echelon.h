#ifndef ECHELON_H
#define ECHELON_H

#include "lib/matrix.h"
#include <iostream>
#include <vector>
#include <limits>

namespace tiele {
    /// @brief find Reduced Row Echelon form
    /// @param matrix 
    /// @return RREF of inputted matrix
    Matrix reduced_row_echelon(const Matrix& matrix);

    /// @brief  find Row Echelon form 
    /// @param matrix 
    /// @return REF of inputted matrix
    Matrix row_echelon_form(const Matrix& matrix);
}

#endif