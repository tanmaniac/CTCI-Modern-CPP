#pragma once

#include "ForwardList.h"

namespace linkedlists {
/**
 * @brief Given a circular linked list, implement an algorithm that returns the node at the
 * beginning of the loop.
 *
 * DEFINITION
 * Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier
 * node, so as to make a loop in the linked list. EXAMPLE Input: A -) B -) C -) 0 -) E - ) C
 *
 * Output: C
 *
 * @tparam T
 * @param head Head of input list
 * @return std::shared_ptr<ll::ForwardListNode<T>>
 */
template <typename T>
std::shared_ptr<ll::ForwardListNode<T>>
    loopDetect(const std::shared_ptr<ll::ForwardListNode<T>> head) {
    // Trivial case
    if (head == nullptr) {
        return nullptr;
    }

    auto slow = head;
    auto fast = head;

    // Walk the loop until we either hit the end, or the slow pointer is at the same node as the
    // fast pointer
    while (slow != nullptr && fast != nullptr && fast->_next != nullptr) {
        // Move pointers up
        slow = slow->_next;
        fast = fast->_next->_next;

        // If they're both pointing to the same thing, shift the pointers up along with the head
        // until they're all together
        if (slow == fast) {
            // There's a loop!
            auto headCpy = head;
            while (headCpy != slow) {
                headCpy = headCpy->_next;
                slow = slow->_next;
            }
            return slow;
        }
    }

    // No loop
    return nullptr;
}
} // namespace linkedlists