#include "collections.h"

namespace collections {

/**
 * Inline implementations of custom type list<T> that is derived from
 * the standard type std::list<T>. A list has properties:
 * - a list is ordered (0, 1, 2, 3rd element), access i-th element
 * - may contain duplicates (same values multiple times)
 * 
 * Constructors:
 * - list(const list<T>& from_other) - copy constructor from other list
 * - list(const set<T>& from_set)    - copy constructor from other set
 * 
 * Operations:
 * - add(T &value)          - append value to list
 * - &list<T> << T &value   - operator '<<' to append value to a list
 * - T& at(i)               - return the i-th element of the list
 * - T& [i]                 - operator '[i]' that returns the i'th element
 * - insertAt(i, T &value)  - insert value after the i-th position
 * - removeAt(i)            - remove the i-th value (from the begin)
 * - removeFromEnd(i)       - remove the i-th value (from the end)
 * - contains(T &value)     - return true if list contains value
 * - copy()                 - return a copy of the list
 * - print()                - print list
 * - ostream& << &list<T>   - operator '<<' to output list to ostream&
 */

template <typename T>
list<T>::list(const list<T>& from_other) : std::list<T>(from_other) { }

template <typename T>
list<T>::list(const set<T>& from_set) : std::list<T>() {
    for (const auto &item : from_set) {
        add(item);
    }
}

template <typename T>
list<T>& list<T>::add(const T &value) {
    this->push_back(value);
    return *this;
}

template <typename T>
list<T>& list<T>::operator<<(const T &value) {
    this->push_back(value);
    return *this;
}

template <typename T>
T& list<T>::at(const int i) {
    if (i < 0 || static_cast<size_t>(i) >= this->size()) {
        throw std::out_of_range("Index out of range");
    }
    auto it = this->begin();
    std::advance(it, i);
    return *it;
}

template <typename T>
T& list<T>::operator[](const int i) {
    return at(i);
}

template <typename T>
list<T>& list<T>::insertAt(const size_t index, const T &value) {
    if (index > this->size()) {
        throw std::out_of_range("Index out of range");
    }
    auto it = this->begin();
    std::advance(it, index);
    this->insert(it, value);
    return *this;
}

template <typename T>
T& list<T>::removeAt(const size_t index) {
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
T& list<T>::removeFromEnd(const size_t index) {
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
 * Inline implementations of custom type set<T> derived from the standard
 * type std::set<T>. A set has properties:
 * - a set has no order, no access of the i-th element
 * - does not contain duplicates (same values multiple times)
 * 
 * Constructors:
 * - set(const set<T>& from_other) - copy constructor from other set
 * - set(const list<T>& from_list) - copy constructor from other list
 * 
 * Operations:
 * - put(T &value)          - put value into set (replaces prior value, if exists)
 * - &set<T> << T &value    - operator '<<' to put value into set
 * - remove(T &value)       - remove value from set
 * - contains(T &value)     - return true if set contains value
 * - copy()                 - return a copy of the set
 * - print()                - print set
 * - ostream& << &set<T>    - operator '<<' to output the set to ostream&
 */

template <typename T>
set<T>::set(const set<T>& from_other) : std::set<T>(from_other) { }

template <typename T>
set<T>::set(const list<T>& from_list) : std::set<T>() {
    for (const auto &item : from_list) {
        put(item);
    }
}

template <typename T>
set<T> &set<T>::put(const T &value) {
    this->insert(value);
    return *this;
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
set<T>& set<T>::copy() const {
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
