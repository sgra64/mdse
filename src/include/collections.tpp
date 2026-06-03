#include "collections.h"

namespace collections {

/**
 * Definition of custom type list<T> derived from the standard type
 * std::list<T>. A list has properties:
 * - a list is ordered (0, 1, 2, 3rd element), access i-th element
 * - may contain duplicates (same values multiple times)
 * 
 * Operations:
 * - add(T &value)          - add value to list
 * - &list<T> << T &value   - operator to add value to list
 * - insertAt(i, T &value)  - insert value after i-th position
 * - removeAt(i)            - remove i-th value (from begin)
 * - removeFromEnd(i)       - remove i-th value (from end)
 * - contains(T &value)     - return true if list contains value
 * - copy()                 - return copy of list
 * - print()                - print list
 * - ostream& << &list<T>   - operator to output list to ostream&
 */
template <typename T>
list<T>::list(const list<T>& other) : std::list<T>(other) {}

template <typename T>
void list<T>::add(const T &value) {
    this->push_back(value);
}

template <typename T>
list<T>& list<T>::operator<<(const T &value) {
    this->push_back(value);
    return *this;
}

// template <typename T>
// list<T>& list<T>::operator>>(const T &value) {
//     this->push_front(value);
//     return *this;
// }

template <typename T>
void list<T>::insertAt(const size_t index, const T &value) {
    if (index > this->size()) {
        throw std::out_of_range("Index out of range");
    }
    auto it = this->begin();
    std::advance(it, index);
    this->insert(it, value);
}

template <typename T>
T list<T>::removeAt(const size_t index) {
    if (index >= this->size()) {
        throw std::out_of_range("Index out of range");
    }
    auto it = this->begin();
    std::advance(it, index);
    T value = *it;
    this->erase(it);
    return value;
}

template <typename T>
T list<T>::removeFromEnd(const size_t index) {
    if (index >= this->size()) {
        throw std::out_of_range("Index out of range");
    }
    auto it = this->end();
    std::advance(it, -static_cast<int>(index) - 1);
    T value = *it;
    this->erase(it);
    return value; 
}

template <typename T>
bool list<T>::contains(const T &value) const {
    for (const auto &item : *this) {
        if (item == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
list<T> list<T>::copy() const {
    return *this;
}

template <typename T>
void list<T>::print() const {
    std::cout << *this << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const list<T>& list) {
    bool first = true;
    os << "[";
    for (const auto &item : list) {
        os << (first ? "" : ", ") << item;
        first = false;
    }
    return os << "]";
}


/**
 * Definition of custom type set<T> derived from the standard type
 * std::set<T>. A set has properties:
 * - a set has no order, no access of the i-th element
 * - does not contain duplicates (same values multiple times)
 * 
 * Operations:
 * - put(T &value)          - put value to set
 * - &set<T> << T &value    - operator to put value into set
 * - remove(T &value)       - remove value from set
 * - contains(T &value)     - return true if set contains value
 * - copy()                 - return copy of set
 * - print()                - print set
 * - ostream& << &set<T>    - operator to output the set to ostream&
 */

template <typename T>
set<T>::set(const set<T>& other) : std::set<T>(other) {}

template <typename T>
void set<T>::put(const T &value) {
    this->insert(value);
}

template <typename T>
set<T>& set<T>::operator<<(const T &value) {
    this->insert(value);
    return *this;
}

template <typename T>
void set<T>::remove(const T &value) {
    this->erase(value);
}

template <typename T>
bool set<T>::contains(const T &value) const {
    for (const auto &item : *this) {
        if (item == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
set<T> set<T>::copy() const {
    return *this;
}

template <typename T>
void set<T>::print() const {
    std::cout << *this << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& set) {
    bool first = true;
    os << "{";
    for (const auto &item : set) {
        os << (first ? "" : ", ") << item;
        first = false;
    }
    return os << "}";
}

} // collections
