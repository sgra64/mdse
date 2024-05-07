#ifndef NUMBERS_H
#define NUMBERS_H
#include <vector>
#include <set>
#include <utility>
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
    int sum(const vector<int> &numbers);

    /**
     * Aufgabe 2
     *
     * @brief return the sum of positive even numbers.
     *
     * @param numbers numbers given
     * @return sum of positive even numbers
     */
    int sum_positive_even_numbers(const vector<int> &numbers);

    /**
     * Aufgabe 3
     *
     * @brief sum_recursive computes the sum of without loops (for, while, do-while)
     * using recursion.
     *
     * @param i index of element in numbers
     * @param numbers numbers given
     * @return sum of numbers
     */
    int sum_recursive(const int i, const vector<int> &numbers);

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
    int find_first(const int x, const vector<int> &numbers);

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
    int find_last(const int x, const vector<int> &numbers);

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
    vector<int> &find_all(const int x, const vector<int> &numbers);

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
    vector<pair<int, int>> &find_sums(const int sum, const vector<int> &numbers);

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
    set<set<int>> &find_all_sums(const int sum, const vector<int> &numbers);


    /**
     * main() function in Numbers namespace.
     * @param argc number of command line arguments in argv
     * @param argv command line arguments
     */
    int main(int argc, char *argv[]);

}
#endif // NUMBERS_H