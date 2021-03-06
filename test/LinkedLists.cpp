#include "include/linked-lists/DelMiddleNode.h"
#include "include/linked-lists/ForwardList.h"
#include "include/linked-lists/Intersection.h"
#include "include/linked-lists/KthToLast.h"
#include "include/linked-lists/LoopDetection.h"
#include "include/linked-lists/Palindrome.h"
#include "include/linked-lists/Partition.h"
#include "include/linked-lists/RemoveDups.h"
#include "include/linked-lists/SumLists.h"

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
        EXPECT_EQ(testVec[i], head->value());
        head = head->_next;
    }
}

TEST(LINKED_LISTS, CREATE_LIST_W_INITIALIZER) {
    std::vector<int> testVec{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    ll::ForwardList<int> testList{{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    EXPECT_EQ(testList.size(), testVec.size());

    // Iterate over the test list and make sure the nodes are correct
    auto head = testList.getHead();
    for (size_t i = 0; i < testVec.size(); i++) {
        EXPECT_EQ(testVec[i], head->value());
        head = head->_next;
    }
}

TEST(LINKED_LISTS, REMOVE_DUPS) {
    ll::ForwardList<int> testList{{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}};
    std::vector<int> expectedOut{{1, 2, 3, 4, 5}};

    linkedlists::removeDups(testList);

    // Verify output
    auto head = testList.getHead();
    for (size_t i = 0; i < expectedOut.size(); i++) {
        EXPECT_EQ(expectedOut[i], head->value());
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

TEST(LINKED_LISTS, DEL_MIDDLE_NODE) {
    std::vector<int> testVec{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};

    ll::ForwardList<int> testList;
    for (const auto& val : testVec) {
        testList.appendToTail(val);
    }

    // Get the 6th node (value = 5)
    auto head = testList.getHead();
    for (int i = 0; i < 6; i++) {
        head = head->_next;
    }
    // sanity check
    EXPECT_EQ(head->value(), testVec[6]);

    linkedlists::delMiddleNode(head);

    testVec.erase(testVec.begin() + 6);

    head = testList.getHead();
    int i = 0;
    while (head != nullptr) {
        EXPECT_EQ(head->value(), testVec[i]);
        head = head->_next;
        i++;
    }
    EXPECT_EQ(i, testVec.size());
}

TEST(LINKED_LISTS, PARTITION) {
    std::vector<int> testVec{{3, 5, 8, 5, 10, 2, 1}};
    const int partitionVal = 5;

    ll::ForwardList<int> testList;
    for (const auto& val : testVec) {
        testList.appendToTail(val);
    }

    ll::ForwardList<int> partitioned = linkedlists::partition(testList, partitionVal);

    bool lessThan = true;
    auto head = partitioned.getHead();
    while (head != nullptr) {
        if (head->value() >= partitionVal) {
            // flip switch
            lessThan = false;
        }
        if (lessThan) {
            EXPECT_LT(head->value(), partitionVal);
        } else {
            EXPECT_GE(head->value(), partitionVal);
        }

        head = head->_next;
    }
}

TEST(LINKED_LISTS, SUM_LISTS) {
    std::vector<int> testVec1{{7, 1, 6}};
    std::vector<int> testVec2{{5, 9, 4}};

    ll::ForwardList<int> list1, list2;
    for (const auto& val : testVec1) {
        list1.appendToTail(val);
    }
    for (const auto& val : testVec2) {
        list2.appendToTail(val);
    }

    ll::ForwardList<int> sum = linkedlists::sumLists(list1, list2);

    std::vector<int> expectedOut{{2, 1, 1, 1}};
    auto head = sum.getHead();
    size_t idx = 0;
    while (head != nullptr) {
        EXPECT_EQ(head->value(), expectedOut[idx]);
        head = head->_next;
        idx++;
    }
}

TEST(LINKED_LISTS, PALINDROME) {
    ll::ForwardList<int> listEven{{1, 2, 3, 4, 5, 4, 3, 2, 1}};
    ll::ForwardList<int> listOdd{{1, 2, 3, 4, 5, 5, 4, 3, 2, 1}};

    EXPECT_TRUE(linkedlists::isPalindrome(listEven.getHead()));
    EXPECT_TRUE(linkedlists::isPalindrome(listOdd.getHead()));

    // Modify lists so they're no longer palindromes
    listEven.appendToTail(0);
    listOdd.appendToTail(0);
    EXPECT_FALSE(linkedlists::isPalindrome(listEven.getHead()));
    EXPECT_FALSE(linkedlists::isPalindrome(listOdd.getHead()));
}

TEST(LINKED_LISTS, INTERSECTION) {
    ll::ForwardList<int> list1{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    // Shift forward and tack on some more nodes
    auto head1 = list1.getHead();
    for (int i = 0; i < 4; i++) {
        head1 = head1->_next;
    }
    ll::ForwardList<int> list2{{11, 12}};
    list2.getTail()->_next = head1;

    EXPECT_EQ(linkedlists::intersects(list1.getHead(), list2.getHead()), head1);

    // Try with a non-intersection
    ll::ForwardList<int> list3{{13, 14, 15, 16, 17}};
    EXPECT_EQ(linkedlists::intersects(list1.getHead(), list3.getHead()), nullptr);
}

TEST(LINKED_LISTS, LOOP_DETECT) {
    ll::ForwardList<char> list{{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

    EXPECT_EQ(linkedlists::loopDetect(list.getHead()), nullptr);

    // Create a loop using the 'c' node
    auto head = list.getHead();
    for (int i = 0; i < 2; i++) {
        head = head->_next;
    }
    list.getTail()->_next = head;

    EXPECT_EQ(linkedlists::loopDetect(list.getHead()), head);
}