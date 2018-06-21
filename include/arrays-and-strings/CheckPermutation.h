#pragma once

#include <array>

static constexpr size_t ASCII_CHAR_SPACE = 256;

namespace strings {
/**
 * \brief Given two strings, write a method to decide if one is a permutation of the other.
 *
 * Computational complexity: O(n); Memory complexity: O(1) since the data structure required is
 * constant-sized
 *
 * \param input1 First input string
 * \param input2 Second input string
 * \return bool True if the two strings are permutations of each other; false if not.
 */
bool isPermutation(const std::string& input1, const std::string& input2) {
    // If the two input strings aren't the same size, we can quit immediately
    if (input1.size() != input2.size()) {
        return false;
    }

    std::array<int, ASCII_CHAR_SPACE> charCounts{0};

    // Increment character counts at indices corresponding to each character in input1
    for (const char& c : input1) {
        charCounts[static_cast<int>(c)]++;
    }

    // Decrement for input2
    for (const char& c : input2) {
        charCounts[static_cast<int>(c)]--;
    }

    // Iterate over charCounts and return if there is a nonzero value
    for (const auto& count : charCounts) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

}; // namespace strings
