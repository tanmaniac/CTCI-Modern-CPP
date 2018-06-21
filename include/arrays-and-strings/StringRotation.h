#pragma once

#include <string>

namespace strings {
/**
 * \brief Assume you have a method isSubst ring which checks if one word is a substring of another.
 * Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one call
 * to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
 *
 * \param s1 First input string
 * \param s2 Second input string
 */
bool isRotation(const std::string& s1, const std::string& s2) {
    // If the input strings aren't the same length, then they obviously are not a rotation of one
    // another
    if (s1.length() != s2.length()) {
        return false;
    }

    // Append s2 to itself and search for s1 in it
    std::string s2Combined = s2 + s2;
    size_t pos = s2Combined.find(s1);
    // If pos is within s2Combined, then we found a copy of s1, so s2 must be a rotation of s1
    return pos != std::string::npos;
}
} // namespace strings