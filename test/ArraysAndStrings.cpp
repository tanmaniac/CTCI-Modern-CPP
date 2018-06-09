#include "include/arrays-and-strings/CheckPermutation.h"
#include "include/arrays-and-strings/IsUnique.h"
#include "include/arrays-and-strings/PermutationPalindrome.h"
#include "include/arrays-and-strings/URLify.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(STRINGS, IS_UNIQUE) {
    const std::string expectTrue = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    EXPECT_TRUE(strings::isUnique(expectTrue));

    const std::string expectFalse = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZa";
    EXPECT_FALSE(strings::isUnique(expectFalse));
}

TEST(STRINGS, CHECK_PERMUTATION) {
    {
        const std::string in1 = "abbccc";
        const std::string in2 = "abcccb";
        EXPECT_TRUE(strings::isPermutation(in1, in2));
    }
    {
        const std::string in1 = "abbccc";
        const std::string in2 = "abcccd";
        EXPECT_FALSE(strings::isPermutation(in1, in2));
    }
}

TEST(STRINGS, URLIFY) {
    const std::string input = "Mr John Smith";
    const std::string expectedOut = "Mr%20John%20Smith";

    std::string output;
    strings::urlify(input, output);

    EXPECT_TRUE(expectedOut.compare(output) == 0);
}

TEST(STRINGS, PALINDROME_PERMUTATION) {
    const std::string input = "Mr. Owl ate my metal worm";
    EXPECT_TRUE(strings::isPermOfPalindrome(input));

    const std::string badInput = "Taco Catz";
    EXPECT_FALSE(strings::isPermOfPalindrome(badInput));
}