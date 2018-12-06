#pragma once

#include "ForwardList.h"

namespace linkedlists {
namespace isn {
template <typename T>
size_t getSize(const std::shared_ptr<ll::ForwardListNode<T>> head) {
    auto headCpy = head;
    size_t size = 0;

    while (headCpy != nullptr) {
        headCpy = headCpy->_next;
        size++;
    }

    return size;
}
} // namespace isn

/**
 * @brief Given two (singly) linked lists, determine if the two lists intersect. Return the
 * intersecting node. Note that the intersection is defined based on reference, not value. That is,
 * if the kth node of the first linked list is the exact same node (by reference) as the jth node of
 * the second linked list, then they are intersecting.
 *
 * This solution takes O(A + 2B) time, where A is the length of the longer list and B is the length
 * of the shorter one. It takes O(1) memory since it doesn't use recursion.
 *
 */
template <typename T>
std::shared_ptr<ll::ForwardListNode<T>> intersects(std::shared_ptr<ll::ForwardListNode<T>> head1,
                                                   std::shared_ptr<ll::ForwardListNode<T>> head2) {
    // Trivial case
    if (head1 == nullptr && head2 == nullptr) {
        return nullptr;
    }

    // Get list sizes
    size_t head1Size = isn::getSize(head1);
    size_t head2Size = isn::getSize(head2);
    size_t difference = 0;

    std::shared_ptr<ll::ForwardListNode<T>> longer, shorter;
    if (head1Size > head2Size) {
        longer = head1;
        shorter = head2;
        difference = head1Size - head2Size;
    } else {
        longer = head2;
        shorter = head1;
        difference = head2Size - head1Size;
    }

    // Move the head of the longer list up so it's the same length as the shorter one
    for (size_t i = 0; i < difference; i++) {
        longer = longer->_next;
    }

    // Determine if there's an intersection now
    while (longer != nullptr && shorter != nullptr) {
        if (longer == shorter) {
            return longer;
        } else {
            longer = longer->_next;
            shorter = shorter->_next;
        }
    }

    return nullptr;
}
}; // namespace linkedlists