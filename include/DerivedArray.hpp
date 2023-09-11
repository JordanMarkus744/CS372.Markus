#include <iostream>
#include "SequentialContainer.hpp"
#pragma once

template <typename T>
class Array : public SeqContainer<T> {
public:

    Array(size_t size) : SeqContainer<T>(size) {}

    // You don't need to redefine the destructor or other functions because
    // they are inherited from SeqContainer.

    T &at(int index) {
        // Use the inherited function from SeqContainer.
        return SeqContainer<T>::at(index);
    }

    int Size() {
        // Use the inherited function from SeqContainer.
        return SeqContainer<T>::Size();
    }

    typename SeqContainer<T>::iterator insert(typename SeqContainer<T>::iterator itr, const T &x) {
        return SeqContainer<T>::insert(itr, x);
    }
    // You can also use the inherited iterators from SeqContainer.

    // No need to redefine operator== and operator= since they use SeqContainer's functions.

    // No need to redefine operator[] since it uses at().

    // You don't need to redefine other functions.

};