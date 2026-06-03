#pragma once
#include <iostream>
#include <list>
#include <set>

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
class list : public std::list<T> {

  public:
    using std::list<T>::list;

    list(const list& other);

    void add(const T &value);

    list& operator<<(const T &value);

    // list& operator>>(const T &value);

    void insertAt(const size_t index, const T& value);

    T removeAt(const size_t index);

    T removeFromEnd(const size_t index);

    bool contains(const T &value) const;

    list copy() const;

    void print() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const list<U>& list);
};


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
class set : public std::set<T> {

  public:
    using std::set<T>::set;

    set(const set& other);

    void put(const T &value);

    set& operator<<(const T &value);

    void remove(const T &value);

    bool contains(const T &value) const;

    set copy() const;

    void print() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const set<U>& set);
};

/**
 * Desclare type of a power-set 'pset' as a set-of-sets.
 */
template<typename T>
using pset = set<set<T>>;

} // collections
