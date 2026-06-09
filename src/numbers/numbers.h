#pragma once
#include "collections.h"
// 
namespace NumbersNS {
using namespace collections;

/**
 * Class that provides various calculation methods on numbers.
 */
class Numbers {

  public:
    /**
     * Tell the compiler to emit default cleanup code, equivalent
     * to the implicit destructor, but written explicitly.
     */
    ~Numbers() = default;

    /**
     * Calculate the sum of two numbers (inline method).
     * @param a first operand
     * @param b second operand
     * @return the sum of a and b
     */
    int sum(const int a, const int b) { return a + b; }

    /**
     * Calculate the sum of numbers.
     * @param numbers input list of numbers
     * @return the sum of numbers
     */
    int sum(const list<int> &numbers);

    /**
     * Calculate the sum of positive even numbers.
     * @param numbers input list of numbers
     * @return the sum of positive even numbers
     */
    int sum_positive_even(const list<int> &numbers);

    /**
     * Calculate all pairs of numbers that add to a target sum.
     * @param numbers input list of numbers
     * @param sum the target sum
     * @return all pairs of numbers that add to a target sum
     */
    pset<int> &all_pairs(list<int> &numbers, int sum);

    /**
     * Calculate all combinations of numbers chosen from the
     * input list that add to a target sum.
     * @param numbers input list of numbers
     * @param sum the target sum
     * @return all pairs of numbers that add to a target sum
     */
    pset<int> &all_sums(const list<int> &numbers, int sum);
};

} // NumbersNS

#include "collections.tpp"
