#pragma once

#include "ForwardList.h"

#include <memory>
#include <utility>

namespace linkedlists {
template <typename T>
size_t getSize(const std::shared_ptr<ll::ForwardListNode<T>> list) {
    auto head = list;
    size_t size = 0;

    while (head != nullptr) {
        size++;
        head = head->_next;
    }

    return size;
}

template <typename T>
std::pair<bool, std::shared_ptr<ll::ForwardListNode<T>>>
    isPalindromeHelper(const std::shared_ptr<ll::ForwardListNode<T>> head, const size_t size) {
    using nodePtr = std::shared_ptr<ll::ForwardListNode<T>>;

    // Trivial case
    if (size == 0 || head == nullptr) {
        return std::make_pair(true, nullptr);
    }

    // Base case: we're at the middle of the list
    // Odd number of nodes
    if (size == 1) {
        return std::make_pair(true, head->_next);
    } else if (size == 2) {
        // even number of nodes
        bool matches = (head->value() == head->_next->value());
        return std::make_pair(matches, head->_next->_next);
    }

    bool matches;
    nodePtr next;
    std::tie(matches, next) = isPalindromeHelper(head->_next, size - 2);

    // Immediately fail if the inner step has failed
    if (!matches) {
        return std::make_pair(false, nullptr);
    }

    // Otherwise, return the next one
    return std::make_pair(head->value() == next->value(), next->_next);
}

/**
 * \brief Implement a function to check if a linked list is a palindrome.
 *        This implementation takes O(N) time and O(1) memory. However, since it's recursive, it
 * takes O(N) stack space.
 *
 * \param list Input List
 * \return bool True if it's a palindrome, false if not.
 */
template <typename T>
bool isPalindrome(const std::shared_ptr<ll::ForwardListNode<T>> list) {
    size_t listSize = getSize(list);

    auto result = isPalindromeHelper(list, listSize);

    return result.first;
}
}; // namespace linkedlists