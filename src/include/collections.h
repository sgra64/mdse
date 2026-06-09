#pragma once
#include <iostream>
#include <list>
#include <set>

namespace collections {

template <typename T> class set;

/**
 * Definition of custom type list<T> derived from the standard type
 * std::list<T>. A list has properties:
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
class list : public std::list<T> {

  public:
    using std::list<T>::list;

    // list<T> constructors
    list(const list<T>& from_other);
    list(const set<T>& from_set);

    // methods
    list<T>& add(const T &value);

    list<T>& operator<<(const T &value);

    T& at(const int i);

    T& operator[](const int i);

    list<T>& insertAt(const size_t index, const T& value);

    T& removeAt(const size_t index);

    T& removeFromEnd(const size_t index);

    bool contains(const T &value) const;

    list<T> copy() const;

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
class set : public std::set<T> {

  public:
    using std::set<T>::set;

    // set<T> constructors
    set(const set<T>& from_other);
    set(const list<T>& from_list);

    // methods
    set<T>& put(const T &value);

    set<T>& operator<<(const T &value);

    void remove(const T &value);

    bool contains(const T &value) const;

    set<T>& copy() const;

    void print() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const set<U>& set);
};

/**
 * desclare type of a power-set as set<set<T>> (set-of-sets)
 */
template<typename T>
using pset = set<set<T>>;

} // collections
