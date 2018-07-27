#pragma once

#include <initializer_list>
#include <memory>

#include <iostream>

// Very simple forward list node implementation

// TODO: Provide way to remove node from list

namespace ll {
template <class T, class Allocator = std::allocator<T>>
struct ForwardListNode {
    using nodePtr = typename std::shared_ptr<ForwardListNode<T, Allocator>>;
    using alloc_traits = typename std::allocator_traits<Allocator>;

    T* _value;
    Allocator& _alloc;
    nodePtr _next;

    ForwardListNode(const T value, Allocator& alloc = Allocator(), nodePtr next = nullptr)
        : _alloc(alloc), _next(next) {
        // Allocate memory
        _value = alloc.allocate(1);
        // Construct data. We just call the copy constructor here
        alloc_traits::construct(alloc, _value, value);
    }

    ~ForwardListNode() { alloc_traits::deallocate(_alloc, _value, 1); }

    T& value() { return *_value; }
    const T& value() const { return *_value; }
};

template <class T, class Allocator = std::allocator<T>>
class ForwardList {
public:
    using nodePtr = typename std::shared_ptr<ForwardListNode<T, Allocator>>;
    using alloc_traits = typename std::allocator_traits<Allocator>;
    using size_type = typename alloc_traits::size_type;
    using value_type = typename alloc_traits::value_type;
    using reference = typename Allocator::reference;
    using const_reference = typename Allocator::const_reference;
    using difference_type = typename alloc_traits::difference_type;

private:
    nodePtr _head, _tail;
    size_type _size = 0;
    Allocator _alloc;

    nodePtr createNode(reference value, nodePtr next = nullptr);
    nodePtr createNode(const_reference value, nodePtr next = nullptr);

public:
    /**
     * Default constructor - constructs an empty list
     */
    ForwardList() : _head(nullptr), _tail(nullptr), _size(0) {}

    /**
     * Constructor - constructs a ForwardList using an initializer list
     */
    ForwardList(const std::initializer_list<T>& list);

    ~ForwardList() = default;

    nodePtr pushFront(reference value);
    nodePtr appendToTail(reference value);
    nodePtr pushFront(const_reference value);
    nodePtr appendToTail(const_reference value);

    nodePtr getHead() { return _head; }
    nodePtr getTail() { return _tail; }
    const size_type size() const { return _size; }
};

//------------------------- Implementations -------------------------//
template <class T, class Allocator>
ForwardList<T, Allocator>::ForwardList(const std::initializer_list<T>& list) {
    for (auto& val : list) {
        appendToTail(val);
    }
}

template <class T, class Allocator>
typename ForwardList<T, Allocator>::nodePtr
    ForwardList<T, Allocator>::createNode(typename ForwardList<T, Allocator>::reference value,
                                          typename ForwardList<T, Allocator>::nodePtr next) {
    return std::make_shared<ForwardListNode<T, Allocator>>(value, _alloc, next);
}

template <class T, class Allocator>
typename ForwardList<T, Allocator>::nodePtr
    ForwardList<T, Allocator>::createNode(typename ForwardList<T, Allocator>::const_reference value,
                                          typename ForwardList<T, Allocator>::nodePtr next) {
    return std::make_shared<ForwardListNode<T, Allocator>>(value, _alloc, next);
}

template <class T, class Allocator>
typename ForwardList<T, Allocator>::nodePtr
    ForwardList<T, Allocator>::pushFront(typename ForwardList<T, Allocator>::reference value) {
    auto newNode = createNode(value, _head);
    _head = newNode;
    _size++;
    return newNode;
}

template <class T, class Allocator>
typename ForwardList<T, Allocator>::nodePtr ForwardList<T, Allocator>::pushFront(
    typename ForwardList<T, Allocator>::const_reference value) {
    auto newNode = createNode(value, _head);
    _head = newNode;
    _size++;
    return newNode;
}

template <class T, class Allocator>
typename ForwardList<T, Allocator>::nodePtr
    ForwardList<T, Allocator>::appendToTail(typename ForwardList<T, Allocator>::reference value) {
    auto newNode = createNode(value);
    if (!_head) {
        _head = newNode;
    }
    if (_tail) {
        _tail->_next = newNode;
    }
    _tail = newNode;
    _size++;
    return newNode;
}

template <class T, class Allocator>
typename ForwardList<T, Allocator>::nodePtr ForwardList<T, Allocator>::appendToTail(
    typename ForwardList<T, Allocator>::const_reference value) {
    auto newNode = createNode(value);
    if (!_head) {
        _head = newNode;
    }
    if (_tail) {
        _tail->_next = newNode;
    }
    _tail = newNode;
    _size++;
    return newNode;
}
} // namespace ll