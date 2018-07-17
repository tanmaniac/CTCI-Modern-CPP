#pragma once

#include "LinkedList.h"

namespace linkedlists {
/**
 * \brief  Write code to partition a linked list around a value x, such that all nodes less than x
 * come before all nodes greater than or equal to x . lf x is contained within the list, the values
 * of x only need to be after the elements less than x (see below) .The partition element x can
 * appear anywhere in the "right partition"; it does not need to appear between the left and right
 * partitions.
 *
 * EXAMPLE
 * Input:
 * 3 -> 5 -> 8 -> 5 - > 10 -> 2 -> 1 [partition = 5)
 * Output:
 * 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 *
 * \param list Input list
 * \param partitionVal Value to partition around
 */
template <class T>
ll::ForwardList<T> partition(ll::ForwardList<T>& list, const T partitionVal) {
    // Not sure what the big deal is with this one, just iterate over the list and create two lists,
    // then merge them
    auto head = list.getHead();
    if (head == nullptr) {
        return list;
    }

    ll::ForwardList<T> left, right;

    while (head != nullptr) {
        if (head->_value < partitionVal) {
            left.appendToTail(head->_value);
        } else {
            right.appendToTail(head->_value);
        }
        head = head->_next;
    }

    // Merge the two lists
    auto tail = left.getTail();
    tail->_next = right.getHead();

    return left;
}
}; // namespace linkedlists