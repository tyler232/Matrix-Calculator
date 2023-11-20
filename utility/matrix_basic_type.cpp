#include "matrix_basic_type.h"

namespace tiele {
    Matrix identity(uint32_t size) {
        Matrix identity(size, size);
        for (uint32_t i = 0; i < size; ++i) {
            identity.setValue(i, i, 1.0);
        }
        return identity;
    }
}