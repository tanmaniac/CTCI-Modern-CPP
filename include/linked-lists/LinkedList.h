#pragma once

#include <initializer_list>
#include <memory>

// Very simple forward list node implementation

// TODO: Provide way to remove node from list

namespace ll {
template <class T>
struct ForwardListNode {
    T _value;
    std::shared_ptr<ForwardListNode> _next;

    ForwardListNode(T value) : _value(value), _next(nullptr) {}
    ~ForwardListNode() = default;
};

template <class T>
class ForwardList {
public:
    using nodePtr = typename std::shared_ptr<ForwardListNode<T>>;

private:
    nodePtr _head, _tail;
    size_t _size;

public:
    ForwardList() : _head(nullptr), _tail(nullptr), _size(0) {}
    ~ForwardList() = default;

    nodePtr pushFront(T value) {
        nodePtr newNode = std::make_shared<ForwardListNode<T>>(value);
        newNode->_next = _head;
        _head = newNode;
        _size++;
        return newNode;
    }

    nodePtr appendToTail(T value) {
        nodePtr newNode = std::make_shared<ForwardListNode<T>>(value);
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

    nodePtr getHead() { return _head; }
    const size_t size() const { return _size; }
};
} // namespace ll