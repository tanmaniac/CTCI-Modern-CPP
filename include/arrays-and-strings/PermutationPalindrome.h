#pragma once

#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>

namespace strings {
/**
 * \brief Given a string, write a function to check if it is a permutation of a palindrome. A
 * palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rea
 * rrangement of letters. The palindrome does not need to be limited to just dictionary words.
 *
 * \param input Input string
 * \return bool true if the input is a permutation of a palindrome
 */

bool isPermOfPalindrome(const std::string& input) {
    // Convert input string to lowercase and remove characters that are not letters
    std::string lower = input;

    lower.erase(std::remove_if(lower.begin(),
                               lower.end(),
                               [](char c) -> bool {
                                   return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
                               }),
                lower.end());

    std::transform(
        lower.begin(), lower.end(), lower.begin(), [](char c) -> char { return std::tolower(c); });

    // Iterate over the string and flip the corresponding bit in the counting vector
    uint32_t usedChars = 0;
    for (const char& c : lower) {
        uint32_t bit = static_cast<uint32_t>(c - 'a');
        usedChars ^= 1 << bit;
    }

    // If usedChars == 0, then there is an even number of every character in the string; if it is a
    // power of two, then there is only one odd-numbered count of a character; otherwise, it is not
    // a palindrome
    return (usedChars == 0 || (ceil(std::log2(usedChars) == floor(std::log2(usedChars)))));
}

} // namespace strings