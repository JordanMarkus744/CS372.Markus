#include "SequentialContainer.hpp"
template <typename T>
class vector : public SeqContainer<T> {
public:
    vector() : SeqContainer<T>() {}

    // You don't need to redefine the destructor or other functions because
    // they are inherited from SeqContainer.

    void put(T data, int index) {
        // Use the inherited function from SeqContainer.
        SeqContainer<T>::insert(SeqContainer<T>::begin() + index, data);
    }

    void push_back(T data) {
        // Use the inherited function from SeqContainer.
        SeqContainer<T>::insert(SeqContainer<T>::end(), data);
    }

    T &at(int index) {
        // Use the inherited function from SeqContainer.
        return SeqContainer<T>::at(index);
    }

    int size() {
        // Use the inherited function from SeqContainer.
        return SeqContainer<T>::Size();
    }

    typename SeqContainer<T>::iterator insert(typename SeqContainer<T>::iterator itr, const T &x) {
        return SeqContainer<T>::insert(itr, x);
    }

    // You can also use the inherited iterators from SeqContainer.

    // No need to redefine operator== and operator= since they use SeqContainer's functions.

    T &operator[](int i) {
        // Use the inherited function from SeqContainer.
        return SeqContainer<T>::at(i);
    }

    // You don't need to redefine other functions.

};