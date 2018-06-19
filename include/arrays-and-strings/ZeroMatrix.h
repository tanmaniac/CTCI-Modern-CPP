#pragma once

#include <array>
#include <type_traits>

// loop unrolling
#pragma GCC optimize("unroll-loops")

namespace arrays {
template <typename T, size_t rows, size_t cols>
void zeroMatrix(std::array<std::array<T, cols>, rows>& input) {
    // Make sure the input is arithmetic
    static_assert(std::is_arithmetic<T>::value, "Input must be arithmetic");

    // Determine if we should zero the first row eventually
    bool zeroFirstRow = false;

    for (size_t x = 0; x < cols; x++) {
        if (input[0][x] == 0) {
            zeroFirstRow = true;
            break;
        }
    }

    // Iterate over the input matrix. For each zero in the matrix, set the index in its column and
    // row in the first column and row to 0
    for (size_t y = 0; y < rows; y++) {
        for (size_t x = 0; x < cols; x++) {
            if (input[y][x] == 0) {
                input[0][x] = 0;
                input[y][0] = 0;
            }
        }
    }

    // Iterate over the input matrix and set rows to 0. We don't set the first row to 0 since that
    // would overwrite the zero positions
    for (size_t y = 1; y < rows; y++) {
        if (input[y][0] == 0) {
            for (size_t x = 0; x < cols; x++) {
                input[y][x] = 0;
            }
        }
    }

    // Now set the columns to 0
    for (size_t x = 0; x < cols; x++) {
        if (input[0][x] == 0) {
            for (size_t y = 0; y < rows; y++) {
                input[y][x] = 0;
            }
        }
    }

    // If we previously determined that we need to set the first row to zero, zeroize it
    if (zeroFirstRow) {
        for (size_t x = 0; x < cols; x++) {
            input[0][x] = 0;
        }
    }
}
} // namespace arrays