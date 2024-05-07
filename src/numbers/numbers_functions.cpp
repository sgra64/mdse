#include <iostream>
#include "numbers.h"
using namespace std;

namespace Numbers {

    /**
     * Aufgabe 1
     *
     * @brief return the sum of numbers.
     *
     * @param numbers numbers given
     * @return sum of numbers
     */
    int sum(const vector<int> &numbers) {
        int result = 0;

        /*
         * TODO: implement function
         */
        return result;
    }

    /**
     * Aufgabe 2
     *
     * @brief return the sum of positive even numbers.
     *
     * @param numbers numbers given
     * @return sum of positive even numbers
     */
    int sum_positive_even_numbers(const vector<int> &numbers) {

        /*
         * TODO: implement function
         */
        return 0;
    }

    /**
     * Aufgabe 3
     *
     * @brief sum_no_loop computes the sum of without loops (for, while, do-while)
     * using recursion.
     *
     * @param i index of element in numbers
     * @param numbers numbers given
     * @return sum of numbers
     */
    int sum_recursive(const int i, const vector<int> &numbers) {

        /*
         * TODO: implement function
         */
        return 0;
    }

    /**
     * Aufgabe 4
     *
     * @brief return the index of the first occurence of x in numbers
     * or -1 if x is not found.
     *
     * @param x element to find
     * @param numbers numbers given
     * @return index of first occurence of x or -1 if not found
     */
    int find_first(const int x, const vector<int> &numbers) {

        /*
         * TODO: implement function
         */
        return 0;
    }

    /**
     * Aufgabe 5
     *
     * @brief return the index of the last occurence of x in numbers
     * or -1 if x is not found.
     *
     * @param x element to find
     * @param numbers numbers given
     * @return index of last occurence of x or -1 if not found
     */
    int find_last(const int x, const vector<int> &numbers) {

        /*
         * TODO: implement function
         */
        return 0;
    }

    /**
     * Aufgabe 6
     *
     * @brief return indices of all occurences of x in numbers,
     * returns empty list if x is not found.
     *
     * @param x element to find
     * @param numbers numbers given
     * @return collection of indices of all occurences of x
     */
    vector<int> &find_all(const int x, const vector<int> &numbers) {
        vector<int> *result = new vector<int> {0, 1, 2};
        result->push_back(3);
        result->push_back(4);

        /*
         * TODO: implement function
         */
        return *result;
    }

    /**
     * Aufgabe 7
     *
     * @brief return all pairs [x, y] from numbers that add to sum (x+y),
     * duplicates and mirrors are returned once, e.g. [2, 3], [2, 3] and
     * [3, 2] are reduced to either [2, 3] or [3, 2].
     *
     * @param sum value to which x + y computes
     * @param numbers numbers given
     * @return pairs [x, y] with: x + y == sum.
     */
    vector<pair<int, int>> &find_sums(const int sum, const vector<int> &numbers) {
        vector<pair<int, int>> *result = new vector<pair<int, int>>();
        pair<int, int> *p = new pair<int, int>(1, 2);
        result->push_back(*p);
        p = new pair<int, int>(7, 8);
        result->push_back(*p);

        /*
         * TODO: implement function
         */
        return *result;
    }

    /**
     * Aufgabe 8
     *
     * @brief return all combinations of numbers that add to sum:
     * {x + y + ... } == sum.
     * 
     * For example, sum=14 and numbers: [8, 10, 7, 2, 14, 5, 4]
     * yields: {14}, {8, 2, 4}, {10, 4}
     *
     * @param sum value to which elements add
     * @param numbers numbers given
     * @return sets of numbers {x, y, ... } with: {x + y + ... } == sum.
     */
    set<set<int>> &find_all_sums(const int sum, const vector<int> &numbers) {
        set<set<int>> *result = new set<set<int>>();
        set<int> *s1 = new set<int> {0, 1, 2};
        set<int> *s2 = new set<int> {4};
        s1->insert(3);
        result->insert(*s1);
        result->insert(*s2);

        /*
         * TODO: implement function
         */
        return *result;
    }
}