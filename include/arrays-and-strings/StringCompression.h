#pragma once

#include <sstream>
#include <string>

namespace strings {
/**
 * \brief A method to perform basic string compression using the counts of repeated characters. For
 * example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not
 * become smaller than the original string, your method should return the original string. You can
 * assume the string has only uppercase and lowercase letters (a - z).
 *
 * \param input Input string
 * \return Compressed version of input string
 */
std::string compress(const std::string& input) {
    // If the input string is less than two characters long, we can't compress it any further
    if (input.length() < 2) {
        return input;
    }

    // Get the first character as the current character
    auto inIter = input.begin();
    char current = *inIter;
    int curCount = 1;

    std::stringstream output;
    output << current;
    inIter++;
    // Iterate over the input string
    for (; inIter != input.end(); inIter++) {
        // If the char pointed to by the iterator equals the current character, then we just
        // increment the counter
        if (*inIter == current) {
            curCount++;
        } else {
            output << std::to_string(curCount);
            curCount = 1;
            current = *inIter;
            output << current;
        }
    }

    // Handle the last character
    output << std::to_string(curCount);

    // Make sure the output doesn't exceed the length of the input string
    if (output.str().length() < input.length()) {
        return output.str();
    } else {
        return input;
    }
}
} // namespace strings