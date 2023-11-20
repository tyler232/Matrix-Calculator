#ifndef MATRIX_BASIC_TYPE_H
#define MATRIX_BASIC_TYPE_H

#include "lib/matrix.h"
#include <iostream>
#include <vector>
#include <limits>

namespace tiele {
    /// @brief return a identity matrix of given size
    /// @param size size of rows and cols
    /// @return identity matrix
    Matrix identity(uint32_t size);
}

#endif