<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->
<!-- E: Numbers (Model-driven Software Engineering course C++)
-->
# Assignment *E:* *numbers*

The assignment demonstrates the use of dynamic types `list<T>` and `set<T>`
of data of type `<T>` in *C++*. In contrast to the static *array*-type, which
has a fixed size in memory, dynamic types are designed to hold flexible amounts
of data. They can expand or shrink at run-time.

Main differences between types `list<T>` and `set<T>` are:

- `list<T>`:

    - *order* of elements is relevant,
    
    - direct access to elements by index, e.g. to the first element: `[0]`,
        to the second element: `[1]`, etc.

    - *duplicates* are allowed, e.g. `[1, 2, 2, 3, 3]`. If a duplicate is added,
        it is appended at the end of the list.

- `set<T>`:

    - there is *no order* of elements in a set,

    - there is no direct access to elements by index.

    - there are *no duplicates*, e.g. `[1, 2, 2, 3, 3]`. If a duplicate is added,
        it replaces the prior element.

Operations defined in
[*collections::list*](https://github.com/sgra64/mdse/blob/main/src/include/collections.h)
for the dynamic type `list<T>` are:

```
Constructors:
 - list(const list<T>& from_other) - copy constructor from other list
 - list(const set<T>& from_set)    - copy constructor from other set
 
Operations:
 - add(T &value)          - append value to list
 - &list<T> << T &value   - operator '<<' to append value to a list
 - T& at(i)               - return the i-th element of the list
 - T& [i]                 - operator '[i]' that returns the i'th element
 - insertAt(i, T &value)  - insert value after the i-th position
 - removeAt(i)            - remove the i-th value (from the begin)
 - removeFromEnd(i)       - remove the i-th value (from the end)
 - contains(T &value)     - return true if list contains value
 - copy()                 - return a copy of the list
 - print()                - print list
 - ostream& << &list<T>   - operator '<<' to output list to ostream&
```

Operations defined in
[*collections::set*](https://github.com/sgra64/mdse/blob/main/src/include/collections.h)
for the dynamic type `set<T>` are:

```
Constructors:
 - set(const set<T>& from_other) - copy constructor from other set
 - set(const list<T>& from_list) - copy constructor from other list

Operations:
 - put(T &value)          - put value into set (replaces prior value, if exists)
 - &set<T> << T &value    - operator '<<' to put value into set
 - remove(T &value)       - remove value from set
 - contains(T &value)     - return true if set contains value
 - copy()                 - return a copy of the set
 - print()                - print set
 - ostream& << &set<T>    - operator '<<' to output the set to ostream&
```

Mind the use of the `&` (reference) operator in operations, which avoids using
pointers (`*`). Access to variables using references appears like direct access
to variables using `.` (not `->`), but avoids creating *"by-value"* copies, e.g.
when variables are passed to functions. References are compiled to pointers
internally that can never be *null*.

Modern C++ code should favor the use of `&` references.


&nbsp;

---

The assignment will perform the following steps:

1. [Create new branch: *"numbers"*](#1-create-new-branch-numbers)

1. [Supply Content to new Branch: *"numbers"*](#2-supply-content-to-new-branch-numbers)

1. [Update *Makefile* (automate dependencies)](#3-update-makefile-automate-dependencies)

1. [Class: *Numbers*](#4-class-numbers)

1. [Complete Method: *all_pairs()*](#5-complete-method-all_pairs)

1. [Complete Method: *all_sums()*](#6-complete-method-all_sums)

1. [Final Evaluation (Abnahme)](#7-final-evaluation-abnahme)


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 1. Create new branch: *"numbers"*

As the figure shows, a new branch *"numbers"* is created off the last commit
at the *main* branch:

<img src="https://raw.githubusercontent.com/sgra64/mdse/refs/heads/markup/img/main/git-branches-2-numbers.png" width="600"/>

Preparation:

```sh
# switch to the 'main' branch
git switch main

# show the commit log of the 'main' branch
git log --oneline

# tag the last commit of the 'main' branch
git tag "base"

# show the new tag
git log --oneline
```

Create the new branch:

```sh
# create new local branch 'numbers' off branch 'main' off the 'base' commit
git switch -c numbers base

# show the new branch; 'numbers' is the active branch (*)
git branch -avv
```


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 2. Supply Content to new Branch: *"numbers"*

Setup new remote `mdse-repo` (if not present):

```sh
# show remotes
git remote -v

# setup new remote 'mdse-repo' pointing to 'https://github.com/sgra64/mdse.git'
git remote add mdse-repo https://github.com/sgra64/mdse.git
```

Fetch (or update) remote branches locally:

```sh
# fetch or update remote branch 'mdse-repo/main' locally
git fetch mdse-repo main

# fetch or update remote branch 'mdse-repo/numbers' locally
git fetch mdse-repo numbers

# show remote branches
git branch -avv
```
```
  git-modules               be62b70 update .vscode, settings.json for Code Runner
  main                      ca47f29 update .gitignore, Makefile, src/include/collections
* numbers                   ea65bd3 [mdse-repo/numbers: ahead 2] overlay implementation: src/numbers/numbers.cpp
  remotes/mdse-repo/main    e0d5567 update README.md
  remotes/mdse-repo/numbers c44f4ea update Makefile for making dependencies
```

*"Checkout"* is used to add or update content from other branches for the
current branch. In contrast to *"merge"*, *"checkout"* does not integrate
changes, it simply overwrites existing content in the target branch.

```sh

# update content 'src' from branch 'mdse-repo/main'
git checkout mdse-repo/main -- src

# checkout content 'src/numbers' from branch 'mdse-repo/numbers'
git checkout mdse-repo/numbers -- src
```

Commit new content to branch *numbers* with message: `add src/numbers`:

```sh
# stage and commit new content to branch 'numbers'
git add . && git commit -m "add src/numbers"
```


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 3. Update *Makefile* (automate dependencies)

*Makefile* includes rules and dependencies to build code of a project.
Traditionally, source code files had to be maintained manually in a *Makefile*.
When new *.cpp* or *.h* file were removed or introduced or names of files were
changed, these changes had to be updated in the *Makefile* - causing the risk
of inconsistencies or failures during the build-process.

*Dynamic variables* execute *shell* commands to load current content found
in the project:

```makefile
     OUT := out
    OUTC := $(OUT)/compiled
     SRC := src
 INCLUDE := $(SRC)/include
     CPP := g++ -I./$(INCLUDE)
DEP_FILE := Makefile.dep
# 
# make variables with dynamic content:
    SRCS := $(shell find $(SRC) -name '*.cpp' -not -name "*tempCodeRunner*")
    OBJS := $(patsubst $(SRC)/%.cpp,$(OUTC)/%.o,$(SRCS))
SRC_DIRS := $(shell find $(SRC) -type d)
OBJ_DIRS := $(sort $(dir $(OBJS)))

show_vars:
	@echo "     OUT: $(OUT)"
	@echo "    OUTC: $(OUTC)"
	@echo "     SRC: $(SRC)"
	@echo " INCLUDE: $(INCLUDE)"
	@echo "     CPP: $(CPP)"
	@echo "SRC_DIRS: $(SRC_DIRS)"
	@echo "OBJ_DIRS: $(OBJ_DIRS)"
	@echo "    SRCS: $(SRCS)"
	@echo "    OBJS: $(OBJS)"
	@echo "    DEPS: $(DEPS)"
```

Show the content of dynamic variables:

```sh
make show_vars
```
```
     OUT: out                                   <--- static values
    OUTC: out/compiled
     SRC: src
 INCLUDE: src/include
     CPP: g++ -I./src/include

SRC_DIRS: src src/demo-b1 src/include           <-- dynamic values
OBJ_DIRS: out/compiled/ out/compiled/demo-b1/
    SRCS: src/demo-b1/shape.cpp src/main.cpp
    OBJS: out/compiled/demo-b1/shape.o out/compiled/main.o
```

Tool [*makedepend*](https://linux.die.net/man/1/makedepend) was introduced
early (mid 1980's) to automate the generation of `.o` dependencies
appending the dependency list to the *Makefile*. Using *makedepend* is
largely obsolete today because flags `-MM` and `-MT` of the
[*GNU*](https://en.wikipedia.org/wiki/GNU_Project)
[*gcc / g++*](https://stackoverflow.com/questions/172587/what-is-the-difference-between-g-and-gcc)
compiler also generate the dependency list, but in a separate file that can be
included  at the end of a *Makefile*:


```makefile
# name of the dependency file
DEP_FILE := Makefile.dep

# main goal that builds the link goal and the $(OBJ_DIRS) folders
goal: $(DEP_FILE) $(OUTC) $(OUT)/main

$(DEP_FILE):
	@echo "making '$(DEP_FILE)'"
	@for f in $(SRCS); do \
		obj_path=$(OUTC)/$${f#$(SRC)/}; \
		obj_path=$${obj_path%.cpp}.o; \
		$(CPP) -MM -MT $$obj_path $$f >> $(DEP_FILE); \
	done

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
# include dependency file, if present ('-')
-include $(DEP_FILE)
```

Make the necessary to *Makefile* or update *Makefile* from the *mdse-repo/numbers*
branch for auto-generation of dependencies:

```sh
# checkout improved 'Makefile' from branch 'mdse-repo/numbers'
git checkout mdse-repo/numbers -- Makefile

# re-build the project
make clean && make
```

*Make* generates a new file `Makefile.dep` with auto-generated dependencies
Prior, dependencies were maintained manually at the end of the *Makefile*.

Run command

```sh
# create depenency file 'Makefile.dep'
 make Makefile.dep

 cat Makefile.dep
```

The depenency file includes the list of `.o` files with their dependencies
on source code (`.h`, `.cpp` or `.tpp` files):

```
out/compiled/demo-b1/shape.o:  src/demo-b1/shape.cpp
out/compiled/main.o:  src/main.cpp src/include/collections.h src/include/collections.tpp
```

If this works, commit the updated *Makefile* to branch *numbers* with message:
`update Makefile (auto-generate dependencies)`:

```sh
# stage and commit new content to branch 'numbers'
git add . && git commit -m "update Makefile (auto-generate dependencies)"
```


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 3. Class: *Numbers*

Class *Numbers* in [*src/numbers/numbers.h*](src/numbers/numbers.h) defines
methods that will be implemented in this assignment:

```c++
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
```

Type `pset<T>` defines a set-of-sets (powerset) to store results returned
from methods: `pset<int> &all_pairs()` and `pset<int> &all_sums()`, see
[*collections::list*](https://github.com/sgra64/mdse/blob/main/src/include/collections.h):

```c++
/**
 * desclare type of a power-set as set<set<T>> (set-of-sets)
 */
template<typename T> using pset = set<set<T>>;
```


The implementation of method: `int sum(const int a, const int b)`
is aready included in the header file as an inline method:

```c++

```

Change the invocation in file [*src/main.cpp*](src/main.cpp) to
call *number's* *main()*:

```c++
/**
 * Calculate the sum of two numbers (inline method).
 * @param a first operand
 * @param b second operand
 * @return the sum of a and b
 */
int sum(const int a, const int b) { return a + b; }
```
Other method implementations will be included in file
[*src/numbers/numbers.cpp*](src/numbers/numbers.cpp).


The driver code and some example data sets are included in file
[*src/numbers/numbers_main.cpp*](src/numbers/numbers_main.cpp):

```c++
list<int> numbers = { -2, 4, 9, 4, -3, 4, 9, 5 };

// input data of numbers with no negative numbers and no duplicates
list<int> numb_1 = { 8, 10, 7, 2, 14, 5, 4 };

// input data of a larger set of 24 numbers, no negatives, no duplicates
list<int> numb_2 = {
    371,  682,  446,  754,  205,  972,  600,  163,  541,  672,
     27,  170,  226,    7,  190,  639,   87,  773,  651,  370,
    125,  774,  903,  636
    //                    ,  225,  463,  286,  569,  384,    9
};

// input data of even larger set of 63 numbers, no negatives, no duplicates
list<int> numb_3 = {
        799, 2377,  936, 3498, 1342,  493, 1635, 4676, 1613, 3851,
    1445, 4506, 3346,    7, 2141, 2064, 1491,  908,   78, 3325,
    1756, 3691,   23, 1995, 1800,   15, 2784, 4305,   36, 2532,
    4292, 4802, 2522, 4183, 3261, 2610,  803, 2656,  498, 1668,
    2038, 2194,  440,  463, 4047, 4235, 3931,  756,  521, 4042,
    3302,  485, 1002,  408, 4691, 3387, 3104, 3658, 2241, 4382,
    1220, 3656,  500
};
```


&nbsp;

Implement method: `sum(const list<int> &numbers)` that calculates the sum
over all numbers provided by argument *numbers*. Explore how to iterate over
a list of integer numbers and return the result:

```c++
/**
 * Calculate the sum of numbers.
 * @param numbers input list of numbers
 * @return the sum of numbers
 */
int Numbers::sum(const list<int> &numbers) {
    int result = 0;

    /*
     * your code here...
     */

    return result;
}
```

Uncomment the test-methods in the driver code in file
[*src/numbers/numbers_main.cpp*](src/numbers/numbers_main.cpp):

```c++
int main(int argc, const char *argv[]) {
    ...

    Numbers impl;       // Numbers instance (object)

    // 
    // powerset demo - understand the code in 'pset.cpp'
    set<int> threenumbers;
    threenumbers << 1 << 2 << 3;
    // threenumbers.put(1).put(2).put(3);
    pset<int> pset = psetRecursive(threenumbers);
    // pset<int> pset = pset64bit(threenumbers);
    // 
    os << threenumbers << std::endl;
    os << pset << format(" -- (len: %d)", pset.size()) << std::endl;

    // 
    os << sum_ab_tests(impl, os) << std::endl;              <-- uncomment
    os << sum_numbers_tests(impl, os) << std::endl;         <-- uncomment
    os << sum_positive_even_numbers_tests(impl, os) << std::endl;
    // os << all_pairs_tests(impl, os) << std::endl;
    // os << all_sums_tests(impl, os) << std::endl;
    // os << all_sums_extended_tests(impl, os) << std::endl;
    // 

    return 0;
}
```

Output shows the execution of inline method

- `int sum(const int a, const int b)` with example numbers and method

- `sum(const list<int> &numbers)` applied to the data sets *numbers*,
    *numb_1*, *numb_2* and *numb_3*, :

```
--- Numbers examples:
{1, 2, 3}
{{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}} -- (len: 8)

- sum(10, 12) --> 22                <-- int sum(const int a, const int b)
- sum(999999, 1) --> 1000000
- sum(-999999, -1) --> -1000000

- sum(numbers) --> 30               <-- sum(const list<int> &numbers)
- sum(numb_1) --> 50
- sum(numb_2) --> 10984
- sum(numb_3) --> 141466
```

If this works, commit the state with message: `"sum(numbers) complete"`.


&nbsp;

Complete method: `sum_positive_even(const list<int> &numbers)` that sums up
only positive even numbers.

Run the driver code:

```
- sum_positive_even(numbers) --> 12     <-- sum_positive_even(numbers)
- sum_positive_even(numb_1) --> 38
- sum_positive_even(numb_2) --> 6492
- sum_positive_even(numb_3) --> 80012
```

If this works, commit the state with message: `"sum_positive_even(numbers) complete"`.

Show the git-log that now has four commits on branch *numbers:*

```sh
git log --oneline
```
```
3f773c5 (HEAD -> numbers) sum_positive_even(numbers) complete
78d6cc9 sum(numbers) complete
43b5423 update Makefile (auto-generate dependencies)
f6a916a add src/numbers
\\
ca47f29 (tag: base, main) update .gitignore, Makefile, src/include/collections
8f37db9 add Makefile
a76e7b7 add src
c0da71c add .gitignore
113a5dc (tag: root) initial root commit (empty)
```

The new commits appear on branch *numbers*:

<img src="https://raw.githubusercontent.com/sgra64/mdse/refs/heads/markup/img/main/git-branches-3-numbers.png" width="600"/>


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 4. Complete Method: *all_pairs()*

Complete method: `all_pairs(list<int> &numbers, int sum)` that finds all pairs
from numbers that add to the given target sum.

Run the driver code for data sets `numb_1` and `numb_3`:

```c++
list<int> numb_1 = { 8, 10, 7, 2, 14, 5, 4 };
```

```c++
list<int> numb_3 = {
        799, 2377,  936, 3498, 1342,  493, 1635, 4676, 1613, 3851,
    1445, 4506, 3346,    7, 2141, 2064, 1491,  908,   78, 3325,
    1756, 3691,   23, 1995, 1800,   15, 2784, 4305,   36, 2532,
    4292, 4802, 2522, 4183, 3261, 2610,  803, 2656,  498, 1668,
    2038, 2194,  440,  463, 4047, 4235, 3931,  756,  521, 4042,
    3302,  485, 1002,  408, 4691, 3387, 3104, 3658, 2241, 4382,
    1220, 3656,  500
};
```

for target sums: *10*, *12* and *15* for `numb_1` and *500* and *5000* as
target sums for `numb_3`:


```
- all_pairs(numb_1, 10) --> {{2, 8}}
- all_pairs(numb_1, 12) --> {{2, 10}, {4, 8}, {5, 7}}
- all_pairs(numb_1, 15) --> {{5, 10}, {7, 8}}
- all_pairs(numb_3, 500) --> {{7, 493}, {15, 485}}
- all_pairs(numb_3, 5000) --> {{1342, 3658}, {1613, 3387}}
```

If this works, commit the state with message: `"all_pairs(numbers, sum) complete"`.


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 5. Complete Method: *all_sums()*

Complete method: `all_sums(list<int> &numbers, int sum)` that finds all possible
combinations of numbers from a set that add to the given target sum.

For example, for data set:

```c++
list<int> numb_1 = { 8, 10, 7, 2, 14, 5, 4 };
```

the possible solutions for target sums: *10*, *12*, *14*, *15* and *20* are:

```
- all_sums(numb_1, 10) --> {{2, 8}, {10}}                           --> 2 solutions
- all_sums(numb_1, 12) --> {{2, 10}, {4, 8}, {5, 7}}                --> 3 solutions
- all_sums(numb_1, 14) --> {{2, 4, 8}, {2, 5, 7}, {4, 10}, {14}}    --> 4 solutions
- all_sums(numb_1, 15) --> {{2, 5, 8}, {5, 10}, {7, 8}}             --> 3 solutions
- all_sums(numb_1, 20) --> {{2, 4, 14}, {2, 8, 10}, {5, 7, 8}}      --> 3 solutions
```

This problem cannot be solved by nested *for*-loops like in the *all_pairs*
problem.

The problem must grouped into a broader set of problems:

- *Selection Problems* (Auswahlprobleme) or

    - Selection problems refer to finding an optimal or a fitting *"selection"*
        of an input set. An example is the
        [*Knapsack Problem*](https://en.wikipedia.org/wiki/Knapsack_problem)
        (Rucksackproblem), which aims at finding an optimal selection of items
        given a weight constraint. Another variation of the problem is the
        [*Thief's Knapsack*](https://codeforces.com/blog/entry/90568) where a
        thief aims to maximizing the value of items he can carry under a weight
        limit.

        <img src="https://upload.wikimedia.org/wikipedia/commons/6/68/Knapsack_Problem_Illustration.svg" width="200"/>

        Mathematically, *Selection Problems* can be addressed by evaluating all
        possible selections (the set of all subsets), which is called the
        [*Powerset*](https://www.geeksforgeeks.org/maths/power-sets)
        (*Potenzmenge*).

- *Arrangement Problems* (Anordnungsprobleme).

    - Arrangement problems always consider all choices in all possible orders.
        Examples are hacking a 10-letter code by testing all possible arrangements
        of letters. Another example are deliveries where a shortest route is
        sought connecting all delivery destinations. In this case, the arrangements
        are all possible orders of delivery destinations, which is a variety of the
        [*Traveling Salesman Problem (TSP)*](https://de.wikipedia.org/wiki/Problem_des_Handlungsreisenden)
        (*Problem_des_Handlungsreisenden*).

        Mathematically, *Arrangement Problems* can be addressed by evaluating all
        possible arrangement, which is called a
        [*Permutation*](https://www.geeksforgeeks.org/maths/permutation).

For solving the `all_sums(numbers, int sum)` - problems:

1. Identify under which category the `all_sums(numbers, int sum)` - problems falls.

1. Run the *"powerset-demo"* in
    ```c++
    int main(int argc, const char *argv[]) {
        // 
        // powerset demo - understand the code in 'pset.cpp'
        set<int> threenumbers;
        threenumbers << 1 << 2 << 3;
        // threenumbers.put(1).put(2).put(3);
        pset<int> pset = psetRecursive(threenumbers);
        // pset<int> pset = pset64bit(threenumbers);
        // 
        os << threenumbers << std::endl;
        os << pset << format(" -- (len: %d)", pset.size()) << std::endl;
    }
    ```
    ```
    {1, 2, 3}   <-- input set
    {{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}} -- (len: 8)  <-- powerset
    ```

1. Understand the *Powerset* functions in file [*src/numbers/pset.cpp*](src/numbers/pset.cpp)
    that is used for the *powerset-demo*.

1. Try to build a *"brute-force"* solution that evaluates all subsets returned
    from the powerset function whether the numbers of a subset add to the
    target sum. If they do, collect the subset as solution.

The *"brute-force"* approach will solve the problem for the small data set shown
above.

```c++
int main(int argc, const char *argv[]) {
    ...
    // 
    // os << sum_ab_tests(impl, os) << std::endl;
    // os << sum_numbers_tests(impl, os) << std::endl;
    // os << sum_positive_even_numbers_tests(impl, os) << std::endl;
    // os << all_pairs_tests(impl, os) << std::endl;
    os << all_sums_tests(impl, os) << std::endl;        <-- run the test
    // os << all_sums_extended_tests(impl, os) << std::endl;
}
```

The test will run for the small input set *numb_1* of 7 numbers. The extended test
uses the larger input set *numb_3* with 63 numbers. This cannot be solved by the
*"brute-force"* approach evaluating all sub-sets.

It would require evaluating `2^63` possible selections, which amounts to
`9.223.372.036.854.775.808` (9,22 Trillionen, 9,22 10^18). At GHz-clockspeeds
(10^9), a single CPU would be busy ~10^9 seconds, which is ~32 years.

```c++
int main(int argc, const char *argv[]) {
    ...
    // 
    os << all_sums_tests(impl, os) << std::endl;            <-- run the test
    os << all_sums_extended_tests(impl, os) << std::endl;   <-- run the extended test
}
```

Ask AI to help out and find a solution. In principle, that solution is not
different to the *"powerset"* - solution. It avoids exploring regions of the
search space that cannot yield solutions.

Try to understand what AI answers to prompt:

- *"Implement the all-sum problem in C++ in numbers.cpp using signature:*
    *pset<int> &Numbers::all_sums(const list<int> &numbers, int sum);"*

Once you got a solution, run the extended test:

```
- all_sums(numb_2, 999) --> {
    {7, 27, 163, 205, 226, 371},    <-- each selection of numbers from 'numb_2' adds
    {7, 163, 190, 639},                 to the target sum: 999
    {7, 190, 205, 226, 371},
    {27, 87, 125, 163, 226, 371},
    {27, 163, 170, 639},
    {27, 170, 205, 226, 371},
    {27, 205, 226, 541},
    {27, 972},
    {87, 125, 190, 226, 371},
    {87, 371, 541},
    {125, 163, 170, 541},
    {170, 190, 639},
    {226, 773}
  } --> 13 solutions

- all_sums(numb_2, 1000) --> {
    {7, 27, 87, 125, 754},
    {7, 27, 125, 190, 205, 446},
    {7, 27, 125, 190, 651},
    {7, 27, 125, 205, 636},
    {226, 774}
  } --> 5 solutions

- all_sums(numb_3, 999) --> {
    {7, 23, 36, 440, 493},
    {7, 36, 463, 493},
    {15, 23, 36, 440, 485},
    {15, 23, 440, 521},
    {15, 23, 463, 498},
    {15, 36, 463, 485},
    {15, 78, 408, 498},
    {15, 463, 521},
    {23, 36, 440, 500},
    {36, 463, 500}
  } --> 10 solutions

- all_sums(numb_3, 1000) --> {
    {7, 15, 485, 493},
    {7, 493, 500},
    {15, 23, 36, 78, 408, 440},
    {15, 36, 78, 408, 463},
    {15, 485, 500}
  } --> 5 solutions
```

When it all works, commit the state with message: `"all_sums(numbers, sum) complete"`.


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 6. Final Evaluation (Abnahme)

Run the code for all methods:

```
--- Numbers examples:
{1, 2, 3}
{{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}} -- (len: 8)

- sum(10, 12) --> 22
- sum(999999, 1) --> 1000000
- sum(-999999, -1) --> -1000000

- sum(numbers) --> 30
- sum(numb_1) --> 50
- sum(numb_2) --> 10984
- sum(numb_3) --> 141466

- sum_positive_even(numbers) --> 12
- sum_positive_even(numb_1) --> 38
- sum_positive_even(numb_2) --> 6492
- sum_positive_even(numb_3) --> 80012

- all_pairs(numb_1, 10) --> {{2, 8}}
- all_pairs(numb_1, 12) --> {{2, 10}, {4, 8}, {5, 7}}
- all_pairs(numb_1, 15) --> {{5, 10}, {7, 8}}
- all_pairs(numb_3, 500) --> {{7, 493}, {15, 485}}
- all_pairs(numb_3, 5000) --> {{1342, 3658}, {1613, 3387}}

- all_sums(numb_1, 10) --> {{2, 8}, {10}}               --> 2 solutions
- all_sums(numb_1, 12) --> {{2, 10}, {4, 8}, {5, 7}}            --> 3 solutions
- all_sums(numb_1, 14) --> {{2, 4, 8}, {2, 5, 7}, {4, 10}, {14}}                --> 4 solutions
- all_sums(numb_1, 15) --> {{2, 5, 8}, {5, 10}, {7, 8}}         --> 3 solutions
- all_sums(numb_1, 20) --> {{2, 4, 14}, {2, 8, 10}, {5, 7, 8}}          --> 3 solutions

- all_sums(numb_2, 999) --> {
    {7, 27, 163, 205, 226, 371},
    {7, 163, 190, 639},
    {7, 190, 205, 226, 371},
    {27, 87, 125, 163, 226, 371},
    {27, 163, 170, 639},
    {27, 170, 205, 226, 371},
    {27, 205, 226, 541},
    {27, 972},
    {87, 125, 190, 226, 371},
    {87, 371, 541},
    {125, 163, 170, 541},
    {170, 190, 639},
    {226, 773}
  } --> 13 solutions

- all_sums(numb_2, 1000) --> {
    {7, 27, 87, 125, 754},
    {7, 27, 125, 190, 205, 446},
    {7, 27, 125, 190, 651},
    {7, 27, 125, 205, 636},
    {226, 774}
  } --> 5 solutions

- all_sums(numb_3, 999) --> {
    {7, 23, 36, 440, 493},
    {7, 36, 463, 493},
    {15, 23, 36, 440, 485},
    {15, 23, 440, 521},
    {15, 23, 463, 498},
    {15, 36, 463, 485},
    {15, 78, 408, 498},
    {15, 463, 521},
    {23, 36, 440, 500},
    {36, 463, 500}
  } --> 10 solutions

- all_sums(numb_3, 1000) --> {
    {7, 15, 485, 493},
    {7, 493, 500},
    {15, 23, 36, 78, 408, 440},
    {15, 36, 78, 408, 463},
    {15, 485, 500}
  } --> 5 solutions
```

Show the git-log of local branch *numbers:*

```sh
git log --oneline
```
```
96aacec (HEAD -> numbers) all_sums(numbers, sum) complete
a6e178a all_pairs(numbers, sum) complete
3f773c5 sum_positive_even(numbers) complete
78d6cc9 sum(numbers) complete
43b5423 update Makefile (auto-generate dependencies)
f6a916a add src/numbers
\\
ca47f29 (tag: base, main) update .gitignore, Makefile, src/include/collections
8f37db9 add Makefile
a76e7b7 add src
c0da71c add .gitignore
113a5dc (tag: root) initial root commit (empty)
```

<img src="https://raw.githubusercontent.com/sgra64/mdse/refs/heads/markup/img/main/git-branches-4-numbers.png" width="600"/>


&nbsp;

Show the complete git-log with all branches:

```sh
 git log --oneline --graph --all
```
<img src="https://raw.githubusercontent.com/sgra64/mdse/refs/heads/markup/img/main/git-log-4-numbers.png" width="600"/>


<!-- 

#### 4.8 *find_all_sums()*

Results:

```
find_all_sums('numb_1': [8, 10, 7, 2, 14, 5, 4])
 - find_all_sums(10): {{2, 8}, {10}}                           (in any order)
 - find_all_sums(12): {{2, 10}, {4, 8}, {5, 7}}                (in any order)
 - find_all_sums(14): {{2, 4, 8}, {2, 5, 7}, {4, 10}, {14}}    (in any order)
 - find_all_sums(15): {{2, 5, 8}, {5, 10}, {7, 8}}             (in any order)
 - find_all_sums(20): {{2, 4, 14}, {2, 8, 10}, {5, 7, 8}}      (in any order)
```

Weitere Beispiele:

```
find_all_sums('numb_2'), sum=1200
 - result: {
  - {7, 27, 87, 163, 170, 205, 541}, 
  - {7, 87, 163, 170, 773}, 
  - {7, 87, 170, 190, 205, 541}, 
  - {27, 163, 371, 639}, 
  - {87, 205, 226, 682}, 
  - {190, 371, 639}, 
  - {446, 754}
}, solutions: 7
```

```
find_all_sums('numb_2'), sum=999
 - result: {
  - {7, 27, 163, 205, 226, 371}, 
  - {7, 163, 190, 639}, 
  - {7, 190, 205, 226, 371}, 
  - {27, 163, 170, 639}, 
  - {27, 170, 205, 226, 371}, 
  - {27, 205, 226, 541}, 
  - {27, 972}, 
  - {87, 371, 541}, 
  - {170, 190, 639}, 
  - {226, 773}
}, solutions: 10
```


#### 4.8a *find_all_sums()* - XL Solution Space 2^30

Extend array `numb_2` by more numbers: +`651`, +`370`
one after another. Consider execution time.

Special algorithms such as
[branch & bound](https://en.wikipedia.org/wiki/Branch_and_bound)
can be used to find solutions by "cutting branches" of combinations
that cannot yield a solution, e.g. when sum is exceeded.

Expand numbers to 24 numbers, as shown:

```c++
/*
 * Larger set of 24 numbers, no negatives, no duplicates.
 */
const vector<int> &numb_2 = {   // 24 numbers
    371,  682,  446,  754,  205,  972,  600,  163,  541,  672,
     27,  170,  226,    7,  190,  639,   87,  773,  651,  370,
    125,  774,  903,  636//, 225,  463,  286,  569,  384,    9,
}; // add more numbers to find more  solutions
```

Repeat invocation from 4.1.
With the two added numbers, 13 solutions are found (10 before).

```
find_all_sums('numb_2'), sum=999
 - result: {
  - {7, 27, 163, 205, 226, 371}, 
  - {7, 163, 190, 639}, 
  - {7, 190, 205, 226, 371}, 
  - {27, 87, 125, 163, 226, 371}, 
  - {27, 163, 170, 639}, 
  - {27, 170, 205, 226, 371}, 
  - {27, 205, 226, 541}, 
  - {27, 972}, 
  - {87, 125, 190, 226, 371}, 
  - {87, 371, 541}, 
  - {125, 163, 170, 541}, 
  - {170, 190, 639}, 
  - {226, 773}
}, solutions: 13
```

Array `numb_2` started with 24 numbers yielding *2^24* combinations.
The solution space expands rapidely doubling with each number added.
After adding +`225` and +`463`, it is *2^26*.

With all numbers, 44 solutions are found:

```c++
/*
 * Larger set of 30 numbers, no negatives, no duplicates.
 */
const vector<int> &numb_2 = {   // 24 numbers
    371,  682,  446,  754,  205,  972,  600,  163,  541,  672,
     27,  170,  226,    7,  190,  639,   87,  773,  651,  370,
    125,  774,  903,  636 , 225,  463,  286,  569,  384,    9,
};
```

```
find_all_sums('numb_2'), sum=999
 - result: {
  - {7, 9, 27, 87, 125, 170, 190, 384}, - {9, 27, 190, 773}, 
  - {7, 9, 27, 125, 163, 205, 463},     - {9, 87, 903}, 
  - {7, 9, 27, 170, 190, 225, 371},     - {9, 125, 163, 190, 226, 286}, 
  - {7, 9, 27, 170, 190, 226, 370},     - {9, 125, 226, 639}, 
  - {7, 9, 27, 190, 225, 541},          - {9, 163, 170, 286, 371}, 
  - {7, 9, 87, 226, 286, 384},          - {9, 163, 286, 541}, 
  - {7, 9, 125, 170, 225, 463},         - {9, 190, 205, 225, 370}, 
  - {7, 9, 125, 190, 205, 463},         - {27, 87, 125, 163, 226, 371},
  - {7, 27, 87, 190, 225, 463},         - {27, 125, 190, 286, 371},
  - {7, 27, 125, 170, 286, 384},        - {27, 125, 384, 463}, 
  - {7, 27, 163, 205, 226, 371},        - {27, 163, 170, 639}, 
  - {7, 27, 170, 226, 569},             - {27, 170, 205, 226, 371},
  - {7, 87, 125, 170, 226, 384},        - {27, 205, 226, 541}, 
  - {7, 163, 190, 639},                 - {27, 972}, 
  - {7, 170, 225, 226, 371},            - {87, 125, 190, 226, 371}, 
  - {7, 190, 205, 226, 371},            - {87, 163, 286, 463}, 
  - {7, 225, 226, 541},                 - {87, 371, 541}, 
  - {9, 27, 87, 205, 225, 446},         - {125, 163, 170, 541}, 
  - {9, 27, 87, 225, 651},              - {170, 190, 639}, 
  - {9, 27, 125, 170, 205, 463},        - {205, 225, 569},
  - {9, 27, 163, 190, 226, 384},        - {225, 774}, 
  - {9, 27, 163, 205, 225, 370},        - {226, 773}
}, solutions: 44
```

The solution space is now *2^30*.


#### 4.8b *find_all_sums()* - XXL Solution Space 2^63

Array `numb_3` with 63 numbers has a solution space of *2^63*, which
cannot be explored *brute force*.

```c++
/*
 * Even larger set of 63 numbers, no negatives, no duplicates.
 */
const vector<int> numb_3 = {   // n=3, 63 numbers
    799, 2377,  936, 3498, 1342,  493, 1635, 4676,  1613, 3851,
    1445, 4506, 3346,    7, 2141, 2064, 1491,  908,   78, 3325,
    1756, 3691,   23, 1995, 1800,   15, 2784, 4305,   36, 2532,
    4292, 4802, 2522, 4183, 3261, 2610,  803, 2656,  498, 1668,
    2038, 2194,  440,  463, 4047, 4235, 3931,  756,  521, 4042,
    3302,  485, 1002,  408, 4691, 3387, 3104, 3658, 2241, 4382,
    1220, 3656,  500,
};
```

Although only 10 solutions are found from `numb_3` of numbers
yielding sum=999, the space to explore is huge *2^63*.

```
find_all_sums('numb_3'), sum=999
 - result: {
  - {7, 23, 36, 440, 493}, 
  - {7, 36, 463, 493}, 
  - {15, 23, 36, 440, 485}, 
  - {15, 23, 440, 521}, 
  - {15, 23, 463, 498}, 
  - {15, 36, 463, 485}, 
  - {15, 78, 408, 498}, 
  - {15, 463, 521}, 
  - {23, 36, 440, 500}, 
  - {36, 463, 500}
}, solutions: 10
```

Searching for `sum=996`, `sum=500`, `sum=100` and `sum=2000` (30sec).

```
find_all_sums(996): {{7, 15, 36, 440, 498}, {15, 78, 440, 463}}, solutions: 2
find_all_sums(500): {{7, 493}, {15, 485}, {500}}, solutions: 3
find_all_sums(100): {{7, 15, 78}}, solutions: 1
find_all_sums(2000): { ... }, solutions: 38
```

Searching for larger sum-values increases solution time since fewer
branches can be cut. -->
