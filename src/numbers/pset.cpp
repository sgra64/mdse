#include "numbers.h"

namespace NumbersNS {
using namespace collections;

/**
 * @brief Return all subsets of numbers (powerset), including the
 * empty set {}. Numbers vector of size n yield 2^n subsets.
 * 
 * Example: numbers: [1, 2, 3]
 * --> {{}, {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3}, {1, 2, 3}}
 * 
 * Algorithm uses a recursive approach by iterating through numbers
 * and separating the i-th number from numbers yielding a smaller
 * remaining subset (sub-problem, problem reduction).
 * 
 * The algorithm is then applied to the remaining subset yielding
 * the powerset of the reduced sub-problem (recursion).
 * 
 * The resulting subset is duplicated with one copy transferred to
 * the result and the other copy supplemeted with the i-th number
 * (generation).
 * 
 * @param numbers vector of numbers
 * @return all subsets of numbers (powerset)
 */
pset<int> &psetRecursive(const set<int> &numbers) {
    pset<int> &result = *new pset<int>();
    // 
    if(numbers.size()==0) {
        set<int> &empty_set = *new set<int>();
        return result.put(empty_set);   // return empty set: {{}}
    }
    // iterate over elements and solve for sub-problems
    for(auto element : numbers) {
        // 
        // create copy and remove element leaving a sub-problem to solve
        set<int> &subproblem = *new set<int>(numbers);
        subproblem.remove(element);
        // std::cout << "--> numbers: " << numbers << " --> element: " << element << " -- subproblem: " << subproblem << std::endl;
        // 
        // solve sub-problem recursively
        for(auto sub : psetRecursive(subproblem)) {
            // 
            // add each sub-solution to overall solution
            result.put(sub);
            // 
            // make copy of sub-solution, add element and add to overall solution
            set<int> &doub = *new set<int>(sub);
            doub.put(element);
            result.put(doub);
        }
    }
    return result;
}

/**
 * @brief Return all subsets of numbers (powerset), including the
 * empty set {}. Numbers vector of size n yield 2^n subsets.
 * 
 * Example: numbers: [1, 2, 3]
 * --> {{}, {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3}, {1, 2, 3}}
 * 
 * Algorithm uses a 64-bit counter with each bit assigned to a number
 * in numbers. It is included in a subset if the corresponding bit in
 * the counter is set. The counter runs from 0 .. 2^n-1 with n being
 * the size of numbers.
 * 
 * @param numbers vector of numbers
 * @return all subsets of numbers (powerset)
 */
pset<int> &pset64bit(const set<int> &numbers) {
    unsigned int len = numbers.size();
    list<int> &numbers_as_list = *new list<int>(numbers);
    pset<int> &result = *new pset<int>();
    // 
    for(unsigned long i=0; i < ((unsigned long)0x01L << len); i++) {
        set<int> &s1 = *new set<int>();
        // probe if j-th bit is set in i and if, include number[j] to s1
        for(unsigned int j=0; j < len; j++) {
            unsigned long m = 0x0000000000000001L << j;
            if(i & m) {
                s1.insert(numbers_as_list[j]);
            }
        }
        result.put(s1);
    }
    return result;
}

} // NumbersNS
