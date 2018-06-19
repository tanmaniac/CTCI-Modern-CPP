#include "include/arrays-and-strings/CheckPermutation.h"
#include "include/arrays-and-strings/IsUnique.h"
#include "include/arrays-and-strings/OneAway.h"
#include "include/arrays-and-strings/PermutationPalindrome.h"
#include "include/arrays-and-strings/RotateMatrix.h"
#include "include/arrays-and-strings/StringCompression.h"
#include "include/arrays-and-strings/URLify.h"
#include "include/arrays-and-strings/ZeroMatrix.h"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>
#include <vector>

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

TEST(STRINGS, ONE_EDIT_AWAY) {
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> testSets = {
        {{"pale", "bale"}, true},
        {{"pale", "pale"}, true},
        {{"pale", "pales"}, true},
        {{"pale", "ple"}, true},
        {{"pale", "bake"}, false},
        {{"pale", "bakes"}, false}};

    for (const auto& testSet : testSets) {
        EXPECT_EQ(strings::isOneAway(testSet.first.first, testSet.first.second), testSet.second);
    }
}

TEST(STRINGS, COMPRESSION) {
    std::vector<std::pair<std::string, std::string>> testSet = {
        {"aabcccccaaa", "a2b1c5a3"}, {"a", "a"}, {"ab", "ab"}};

    for (const auto& test : testSet) {
        EXPECT_EQ(strings::compress(test.first), test.second);
    }
}

TEST(STRINGS, ROTATE_MATRIX) {
    std::array<std::array<uint32_t, 6>, 6> input = {{{1, 2, 3, 4, 5, 6},
                                                     {7, 8, 9, 10, 11, 12},
                                                     {13, 14, 15, 16, 17, 18},
                                                     {19, 20, 21, 22, 23, 24},
                                                     {25, 26, 27, 28, 29, 30},
                                                     {31, 32, 33, 34, 35, 36}}};

    std::array<std::array<uint32_t, 6>, 6> expectedOutput = {{{31, 25, 19, 13, 7, 1},
                                                              {32, 26, 20, 14, 8, 2},
                                                              {33, 27, 21, 15, 9, 3},
                                                              {34, 28, 22, 16, 10, 4},
                                                              {35, 29, 23, 17, 11, 5},
                                                              {36, 30, 24, 18, 12, 6}}};

    strings::rotateMatrix(input);

    // Verify output
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 6; x++) {
            EXPECT_EQ(input[y][x], expectedOutput[y][x]);
        }
    }
}

TEST(ARRAYS, ZERO_MATRIX) {
    std::array<std::array<uint8_t, 6>, 6> input = {{{1, 1, 1, 0, 1, 1},
                                                    {1, 1, 1, 1, 1, 1},
                                                    {1, 0, 1, 1, 1, 1},
                                                    {1, 1, 1, 1, 0, 1},
                                                    {0, 1, 1, 1, 1, 0},
                                                    {1, 0, 1, 1, 1, 1}}};
    std::array<std::array<uint8_t, 6>, 6> expectedOutput = {{{0, 0, 0, 0, 0, 0},
                                                             {0, 0, 1, 0, 0, 0},
                                                             {0, 0, 0, 0, 0, 0},
                                                             {0, 0, 0, 0, 0, 0},
                                                             {0, 0, 0, 0, 0, 0},
                                                             {0, 0, 0, 0, 0, 0}}};

    arrays::zeroMatrix(input);

    // Verify output
    for (size_t y = 0; y < 6; y++) {
        for (size_t x = 0; x < 6; x++) {
            EXPECT_EQ(input[y][x], expectedOutput[y][x]);
        }
    }
}