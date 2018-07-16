#pragma once

#include "LinkedList.h"

#include <memory>

namespace linkedlists {
/**
 * \brief  Implement an algorithm to delete a node in the middle (i.e., any node but the first and
 * last node, not necessarily the exact middle) of a singly linked list, given only access to that
 * node. This solution requires that the templated class wrapped by the Linked List supports move
 * semantics.
 *
 * Runtime complexity: O(N). Space complexity: O(1).
 *
 * EXAMPLE
 * Input: the node c from the linked list a - >b- >c - >d - >e- >f
 * Result: nothing is returned, but the new linked list looks like a - >b- >d - >e- >f
 *
 * \param delNode Node to be deleted
 */
template <class T>
void delMiddleNode(std::shared_ptr<ll::ForwardListNode<T>>& delNode) {
    if (delNode == nullptr) {
        return;
    }

    // Iterate through the list starting at delNode and move the value from its next node to the
    // current node
    auto curNode = delNode;
    while (curNode->_next != nullptr) {
        curNode->_value = curNode->_next->_value;
        if (curNode->_next->_next == nullptr) {
            // We're at the second to last node, so now just delete the last node
            curNode->_next = nullptr;
        } else {
            // Otherwise just increment normally
            curNode = curNode->_next;
        }
    }
}
}; // namespace linkedlists