#pragma once

#include <cmath>
#include <string>

namespace strings {
/**
 * \brief There are three types of edits that can be performed on strings: insert a character,
 * remove a character, or replace a character. Given two strings, write a function to check if they
 * are one edit (or zero edits) away.
 *
 * \param input1 First input string
 * \param input2 Second input string
 * \return True if the strings are one edit away from each other, false if otherwise
 */

bool isOneAway(const std::string& input1, const std::string& input2) {
    // If the strings differ in length by more than 1, then they are definitely more than one edit
    // away from each other
    if (std::abs(int(input1.length()) - int(input2.length())) > 1) {
        return false;
    }

    std::string shorter = (input1.length() < input2.length()) ? input1 : input2;
    std::string longer = (input1.length() >= input2.length()) ? input1 : input2;

    bool foundDifference = false;
    auto shortIter = shorter.begin();
    auto longIter = longer.begin();

    while (shortIter != shorter.end() && longIter != longer.end()) {
        if (*shortIter != *longIter) {
            if (foundDifference) {
                return false;
            } else {
                foundDifference = true;
            }

            // If the two strings are the same length, then this is a replacement. If lengths are
            // unequal, then this is an insertion
            if (shorter.length() == longer.length()) {
                shortIter++;
            }
        } else {
            // Characters are the same
            shortIter++;
        }

        // Always move longer iterator
        longIter++;
    }

    return true;
}
} // namespace strings