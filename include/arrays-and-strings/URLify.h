#pragma once

#include <algorithm>
#include <iostream>
#include <string>

namespace strings {
/**
 * \brief Write a method to replace all spaces in a string with '%20: You may assume that the string
 * has sufficient space at the end to hold the additional characters, and that you are given the
 * "true" length of the string.
 *
 * \param input Input string
 * \param output Mutable reference to ouput string
 */

void urlify(const std::string& input, std::string& output) {
    const std::string wspace = "%20";
    const std::string delim = " ";

    output = input;
    size_t startPos = 0;
    while ((startPos = output.find(delim, startPos)) != std::string::npos) {
        output.replace(startPos, delim.length(), wspace);
        startPos += wspace.length();
    }
}
} // namespace strings