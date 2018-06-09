#include "include/arrays-and-strings/IsUnique.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(STRINGS, IS_UNIQUE) {
    const std::string expectTrue = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    EXPECT_TRUE(strings::isUnique(expectTrue));

    const std::string expectFalse = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZa";
    EXPECT_FALSE(strings::isUnique(expectFalse));
}