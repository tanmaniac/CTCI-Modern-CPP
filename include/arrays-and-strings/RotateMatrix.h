#pragma once

#include <array>
#include <string>

namespace strings {
/**
 * \brief  Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degrees.
 *
 * \param input N-length array of N-length arrays of unsigned ints representing an image
 */
template <size_t N>
void rotateMatrix(std::array<std::array<uint32_t, N>, N>& input) {
    static_assert(N > 0, "Input size must be greater than 0");

    for (size_t layer = 0; layer < N / 2; layer++) {
        size_t minIdx = layer;
        size_t maxIdx = N - 1 - layer;
        for (size_t i = minIdx; i < maxIdx; i++) {
            size_t offset = i - minIdx;
            // Save the first value that we are swapping
            size_t lastVal = input[minIdx][i];
            input[minIdx][i] = input[maxIdx - offset][minIdx];
            input[maxIdx - offset][minIdx] = input[maxIdx][maxIdx - offset];
            input[maxIdx][maxIdx - offset] = input[i][maxIdx];
            input[i][maxIdx] = lastVal;
        }
    }
}
} // namespace strings