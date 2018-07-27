#pragma once

#include "ForwardList.h"

#include <unordered_set>

namespace linkedlists {
/**
 * \brief  Write code to remove duplicates from an unsorted linked list.
 *
 * \param list Input list
 */
template <class T>
void removeDups(ll::ForwardList<T>& list) {
    auto head = list.getHead();
    if (head == nullptr) {
        return; // Nothing to do
    }
    // Create a set to hold the values in the list
    std::unordered_set<T> values;

    while (head != nullptr && head->_next != nullptr) {
        values.insert(head->value());
        if (values.find(head->_next->value()) != values.end()) {
            // Value already exists in the list
            head->_next = head->_next->_next;
        }
        // Increment head
        head = head->_next;
    }
}
}; // namespace linkedlists