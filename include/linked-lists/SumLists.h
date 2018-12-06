#pragma once

#include "ForwardList.h"

#include <cassert>
#include <cmath>
#include <type_traits>

namespace linkedlists {
/**
 * \brief You have two numbers represented by a linked list, where each node contains a single
 * digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the
 * list. Write a function that adds the two numbers and returns the sum as a linked list.
 *
 * EXAMPLE
 * Input: (7-> 1 -> 6) + (5 -> 9 -> 2) .Thatis,617 + 295.
 * Output: 2 -> 1 -> 9. That is, 912.
 * FOLLOW UP
 * Suppose the digits are stored in forward order. Repeat the above problem.
 * EXAMPLE
 * Input: (6 -> 1 -> 7) + (2 -> 9 -> 5) . That is, 617 + 295.
 * Output: 9 -> 1 -> 2. That is, 912.
 *
 * \param list1 first list
 * \param list2 second list
 * \return sum of the input lists as a linked list.
 */
template <class T>
ll::ForwardList<T> sumLists(ll::ForwardList<T>& list1, ll::ForwardList<T>& list2) {
    assert(std::is_integral<T>::value);

    ll::ForwardList<T> sum;
    T carry = 0;
    auto head1 = list1.getHead();
    auto head2 = list2.getHead();

    while (head1 != nullptr || head2 != nullptr) {
        T digitSum = carry;
        if (head1 != nullptr) {
            digitSum += head1->value();
            head1 = head1->_next;
        }
        if (head2 != nullptr) {
            digitSum += head2->value();
            head2 = head2->_next;
        }
        carry = std::floor(digitSum / 10);
        digitSum = digitSum % 10;
        sum.appendToTail(digitSum);
    }
    // Handle carry
    if (carry > 0) {
        sum.appendToTail(carry);
    }
    return sum;
}
}; // namespace linkedlists