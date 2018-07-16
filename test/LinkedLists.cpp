#include "include/linked-lists/KthToLast.h"
#include "include/linked-lists/LinkedList.h"
#include "include/linked-lists/RemoveDups.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(LINKED_LISTS, CREATE_LIST) {
    // Create a vector with desired data
    std::vector<int> testVec{{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    ll::ForwardList<int> testList;
    for (const auto& val : testVec) {
        testList.appendToTail(val);
    }

    EXPECT_EQ(testList.size(), testVec.size());

    // Iterate over the test list and make sure the nodes are correct
    auto head = testList.getHead();
    for (size_t i = 0; i < testVec.size(); i++) {
        EXPECT_EQ(testVec[i], head->_value);
        head = head->_next;
    }
}

TEST(LINKED_LISTS, REMOVE_DUPS) {
    std::vector<int> testVec{{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}};
    std::vector<int> expectedOut{{1, 2, 3, 4, 5}};

    ll::ForwardList<int> testList;
    for (const auto& val : testVec) {
        testList.appendToTail(val);
    }

    linkedlists::removeDups(testList);

    // Verify output
    auto head = testList.getHead();
    for (size_t i = 0; i < expectedOut.size(); i++) {
        EXPECT_EQ(expectedOut[i], head->_value);
        head = head->_next;
    }
}

TEST(LINKED_LISTS, KTH_TO_LAST) {
    std::vector<int> testVec{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

    ll::ForwardList<int> testList;

    // Test for empty lists
    EXPECT_THROW(linkedlists::kthToLast(testList, 1), std::length_error);

    for (const auto& val : testVec) {
        testList.appendToTail(val);
    }

    // Test for k longer than the length of the input list
    EXPECT_THROW(linkedlists::kthToLast(testList, testVec.size() + 1), std::length_error);

    // Fifth from last is value 6
    const size_t k = 5;
    EXPECT_EQ(linkedlists::kthToLast(testList, k), 6);

    EXPECT_EQ(1, 1);
}