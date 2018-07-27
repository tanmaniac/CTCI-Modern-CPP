#pragma once

#include "ForwardList.h"

#include <sstream>
#include <stdexcept>

namespace linkedlists {
/**
 * \brief  Implement an algorithm to find the kth to last element of a singly linked list.
 *         Time complexity: O(N). Space complexity: O(1).
 *
 * \param list  Input list
 * \param k     kth-to-last element to retreive
 * \return kth-to-last value of the input list.
 */
template <class T>
T kthToLast(ll::ForwardList<T>& list, const size_t k) {
    // Base case
    auto head = list.getHead();
    if (head == nullptr) {
        throw std::length_error("k exceeds length of input list - list is empty");
    }

    // Iterate over list. First we'll iterate k times to get a pointer to the kth value
    auto kthNode = list.getHead();
    // Only go to the last valid index at most
    size_t count = 0;
    while (kthNode->_next != nullptr && count < k - 1) {
        count++;
        kthNode = kthNode->_next;
    }

    // Make sure we actually have the kth value
    if (count != k - 1) {
        std::stringstream err;
        err << "k exceeds length of input list: k = " << k << " but max index = " << count;
        throw std::length_error(err.str());
    }

    // Move both the head and the kthNode pointer until kthNode is at the end
    while (kthNode->_next != nullptr) {
        head = head->_next;
        kthNode = kthNode->_next;
    }

    // head points to the kth to last node
    return head->value();
}
} // namespace linkedlists