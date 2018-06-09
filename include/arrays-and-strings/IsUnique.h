#pragma once

#include <array>

namespace strings {

static constexpr size_t ASCII_CHAR_SPACE = 256;

/**
 * \brief  Implement an algorithm to determine if a string has all unique characters. What if you
 * cannot use additional data structures?
 *
 * \param input Input string
 * \return bool Whether or not the string has all unique characters.
 */

bool isUnique(const std::string& input) {
    std::array<bool, ASCII_CHAR_SPACE> usedChars{0};

    for (const char& c : input) {
        int cBit = static_cast<int>(c);
        if (usedChars[cBit] == true) {
            return false;
        } else {
            usedChars[cBit] = true;
        }
    }

    return true;
}
}; // namespace strings
