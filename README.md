<!-- check-out single branch from repo:
        git clone -b B12 --single-branch https://github.com/sgra64/mdse.git
 -->

# Assignment B2: Numbers

Assignment B2 develops functions for calculations over arrays of numbers.

Numbers are defined in
[src/numbers/numbers.cpp](https://github.com/sgra64/mdse/blob/B12/src/numbers/numbers.cpp):

```c++
// numbers with duplicates and negative numbers
const int numbers_arr[]   = {-2, 4, 9, 4, -3, 4, 9, 5};

const vector<int> numbers = {-2, 4, 9, 4, -3, 4, 9, 5};

// no duplicates and no negative numbers
const vector<int> numb_1 = {8, 10, 7, 2, 14, 5, 4};

const vector<int> numb_2 = {   // n=2, 24 numbers
    371,  682,  446,  754,  205,  972,  600,  163,  541,  672,
     27,  170,  226,    7,  190,  639,   87,  773,  651,  370,
    125,  774,  903,  636//,225,  463,  286,  569,  384,    9,
}; // add more numbers to find more  solutions

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

Functions are defined in
[numbers.h](https://github.com/sgra64/mdse/blob/B12/src/numbers/numbers.h),
summarized:

- `sum(numbers)`                    - calculate sum of numbers[]              (0.5Pt)

- `sum_positive_even_numbers(numbers)` - sum of positive even numbers         (0.5Pt)

- `sum_recursive(numbers)`            - sum of numbers[] without using loops    (0.5Pt)

- `find_first(int x, numbers)`      - find index of first occurrence of x     (0.5Pt)

- `find_last(int x, numbers)`       - find index of last occurrence of x      (0.5Pt)

- `find_all(int x, numbers)`        - find all indices of x in numbers        (0.5Pt)

- `find_sums(int sum, numbers)`     - find all pairs {a, b} with a + b = sum  (1Pt)

- `find_all_sums(int sum, numbers)` - find all combinations of numbers that add to sum (2Pt)


&nbsp;
## Content

1. [Setup](#1-setup)

2. [Build and Run](#2-build-and-run)

3. [Completing Numbers Functions](#3-completing-numbers-functions)

4. [Examples and Solutions](#4-examples-and-solutions)
    - 4.1 [*sum()*](#41-sum)
    - 4.2 [*sum_positive_even_numbers()*](#42-sum_positive_even_numbers)
    - 4.3 [*sum_recursive()*](#43-sum_recursive)
    - 4.4 [*find_first()*](#44-find_first)
    - 4.5 [*find_last()*](#45-find_last)
    - 4.6 [*find_all()*](#46-find_all)
    - 4.7 [*find_sums()*](#47-find_sums)
    - 4.8 [*find_all_sums()*](#48-find_all_sums)


&nbsp;
## 1. Setup

This assignment adds package `numbers` to the project:

```sh
--<cpp>:
 |
 +-- makefile                   # project makefile
 |
 +--<src>                       # source code
 |   +-- main.h                 # header-file with project configuration
 |   +-- main.cpp               # cpp-file with main() function
 |   |
 |   +--<demo>                  # source code of 'demo' sub-project
 |   |   +-- demo.h             # header-file
 |   |   +-- demo.cpp           # cpp-file with Demo::main() function
 |   |
 |   +--<numbers>               # new 'Numbers' package
 |       +-- numbers.h              # header-file with function declarations
 |       +-- numbers_functions.cpp  # cpp-file with function implementations
 |       +-- numbers.cpp            # cpp-file with Numbers::main() function
 |       +-- ostream_helper.h       # helper to print vectors and sets
 |       +-- ostream_helper.cpp     # helper implementation
 |
 +--<out>                       # compiled code
 |   +-- main.o                 # compiled main.cpp
 |   |
 |   +--<demo>
 |   |   +-- demo.o
 |   |
 |   +--<numbers>
 |       +-- numbers.o, numbers_functions.o, ostream_helper.o
 |
```


&nbsp;
## 2. Build and Run

[*make*](https://www.gnu.org/software/make/manual/html_node/Introduction.html)
is a *build tool* for C and C++.

To build the project, run:

```sh
make
```

Output:

```
create out/
g++ -Isrc/demo -Isrc/numbers -g -c -Wall -c src/main.cpp -o out/main.o
create out/demo/
g++ -Isrc/demo -Isrc/numbers -g -c -Wall -c src/demo/demo.cpp -o out/demo/demo.o
create out/numbers/
g++ -Isrc/demo -Isrc/numbers -g -c -Wall -c src/numbers/numbers.cpp -o out/numbers/numbers.o
g++ -Isrc/demo -Isrc/numbers -g -c -Wall -c src/numbers/numbers_functions.cpp -o out/numbers/numbers_functions.o
g++ -Isrc/demo -Isrc/numbers -g -c -Wall -c src/numbers/ostream_helper.cpp -o out/numbers/ostream_helper.o
g++ -o main out/main.o out/demo/demo.o out/numbers/numbers.o out/numbers/numbers_functions.o out/numbers/ostream_helper.o
```

The process creates compiled files in the `out` directory:

```sh
find out
```

Output:

```
out
out/numbers
out/numbers/numbers.o
out/numbers/numbers_functions.o
out/numbers/ostream_helper.o
out/demo
out/demo/demo.o
out/main.o
```

The final step of the *build process* links all compiled files to the main
executable file:

```sh
g++ -o main out/main.o out/demo/demo.o out/numbers/numbers.o out/numbers/numbers_functions.o out/numbers/ostream_helper.o
```

The result of the *build process* is file `main` in the project directory:

```sh
ls -la
```

```
-rwxr-xr-x 1 vscode vscode 519064 May  7 23:03 main
```


Run the program with:

```sh
./main
```

The program prints demo output created in
[src/numbers/numbers.cpp](https://github.com/sgra64/mdse/blob/B12/src/numbers/numbers.cpp).


```
Numbers::main() in numbers.cpp:
[-2, 4, 9, 4, -3, 4, 9, 5] --> sum: 0
[-2, 4, 9, 4, -3, 4, 9, 5] --> sum_positive_even_numbers: 0
[-2, 4, 9, 4, -3, 4, 9, 5] --> sum_recursive: 0
[-2, 4, 9, 4, -3, 4, 9, 5] --> find_first: 0
[-2, 4, 9, 4, -3, 4, 9, 5] --> find_first: 0
[-2, 4, 9, 4, -3, 4, 9, 5] --> find_all: [0, 1, 2, 3, 4]
[-2, 4, 9, 4, -3, 4, 9, 5] --> find_sums: [[1, 2], [7, 8]]
[-2, 4, 9, 4, -3, 4, 9, 5] --> find_all_sums: {{0, 1, 2, 3}, {4}}
```


The *build process* is controlled by the
[*makefile*](https://github.com/sgra64/mdse/blob/B12/makefile):

```
# source directories with header files
INCLUDES = \
	-Isrc/demo \
	-Isrc/numbers

# all compiled files
OBJS = \
	out/main.o \
	out/demo/demo.o \
	out/numbers/numbers.o \
	out/numbers/numbers_functions.o \
	out/numbers/ostream_helper.o

# compiler options
CC=g++
CPPFLAGS=-g -c -Wall


# main goal produces 'main' executable in project directory
main: $(OBJS)
	g++ -o main $(OBJS)

clean:
	rm -rf main out

# rule to compile .o from .cpp files, creates subdirs in out
out/%.o: src/%.cpp
	@[ ! -d $(dir $@) ] && echo create $(dir $@) && mkdir -p $(dir $@) || true
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@

# file dependencies (should be generated using makedepend)
main.cpp:  src/demo/demo.h src/numbers/numbers.h

out/main.o:  src/main.h src/main.cpp
out/demo/demo.o:  src/demo/demo.h src/demo/demo.cpp
out/numbers/numbers.o:  src/numbers/numbers.h src/numbers/numbers.cpp
out/numbers/numbers_functions.o:  src/numbers/numbers.h src/numbers/numbers_functions.cpp
out/numbers/ostream_helper.o:  src/numbers/ostream_helper.h src/numbers/ostream_helper.cpp
```


&nbsp;
## 3. Completing Numbers Functions

After building and running the program, functions can be completed.

Implementation of functions should be performed in
[src/numbers/numbers_functions.cpp](https://github.com/sgra64/mdse/blob/B12/src/numbers/numbers_functions.cpp):

```c++
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
```

Code can be completed, e.g. with:

```c++
int sum(const vector<int> &numbers) {
    int result = 0;
    for(unsigned long i=0; i < numbers.size(); i++) {
        result += numbers[i];
    }
    return result;
}
```

After re-building the project with:

```sh
make
```

the program should print the correct sum:

```
./main
[-2, 4, 9, 4, -3, 4, 9, 5] --> sum: 30
```

Explore also with other numbers arrays: `numbers`, `numb_1`, `numb_2`, `numb_3`.

Results are:

```
numbers:
[-2, 4, 9, 4, -3, 4, 9, 5] --> sum: 30

numb_1:
[8, 10, 7, 2, 14, 5, 4] --> sum: 50

numb_2:
[ 371,  682,  446,  754,  205,  972,  600,  163,  541,  672, 
   27,  170,  226,    7,  190,  639,   87,  773,  651,  370, 
  125,  774,  903,  636] --> sum: 10984

numb_3:
[ 799, 2377,  936, 3498, 1342,  493, 1635, 4676, 1613, 3851, 
 1445, 4506, 3346,    7, 2141, 2064, 1491,  908,   78, 3325, 
 1756, 3691,   23, 1995, 1800,   15, 2784, 4305,   36, 2532, 
 4292, 4802, 2522, 4183, 3261, 2610,  803, 2656,  498, 1668, 
 2038, 2194,  440,  463, 4047, 4235, 3931,  756,  521, 4042, 
 3302,  485, 1002,  408, 4691, 3387, 3104, 3658, 2241, 4382, 
 1220, 3656,  500] --> sum: 141466
```

Complete the other functions 1.) - 8.) in
[src/numbers/numbers_functions.cpp](https://github.com/sgra64/mdse/blob/B12/src/numbers/numbers_functions.cpp):

```
1.) sum(numbers)                    - calculate sum of numbers[].
2.) sum_positive_even_numbers(numbers) - sum of positive even numbers
3.) sum_recursive(numbers)            - sum of numbers[] without using loops
4.) find_first(int x, numbers)      - find index of first occurrence of x
5.) find_last(int x, numbers)       - find index of last occurrence of x
6.) find_all(int x, numbers)        - find all indices of x in numbers
7.) find_sums(int sum, numbers)     - find all pairs {a, b} with a + b = sum
8.) find_all_sums(int sum, numbers) - find all combinations of numbers that add to sum
```


&nbsp;
## 4. Examples and Solutions

This section shows some examples and solutions for *Numbers* - methods:

- 4.1 [*sum()*](#41-sum)
- 4.2 [*sum_positive_even_numbers()*](#42-sum_positive_even_numbers)
- 4.3 [*sum_recursive()*](#43-sum_recursive)
- 4.4 [*find_first()*](#44-find_first)
- 4.5 [*find_last()*](#45-find_last)
- 4.6 [*find_all()*](#46-find_all)
- 4.7 [*find_sums()*](#47-find_sums)
- 4.8 [*find_all_sums()*](#48-find_all_sums)


#### 4.1 *sum()*

Verify *sum()* with all numbers arrays:

Results:

```
Hello, NumbersImpl
sum('numbers': [-2, 4, 9, 4, -3, 4, 9, 5])
 - result: sum() = 30

sum('numb_1': [8, 10, 7, 2, 14, 5, 4])
 - result: sum() = 50

sum('numb_2')
 - result: sum() = 10984

sum('numb_3')
 - result: sum() = 141466
```


#### 4.2 *sum_positive_even_numbers()*

Verify *sum_positive_even_numbers()* with all numbers arrays:

Results:

```
Hello, NumbersImpl
sum_positive_even_numbers('numbers': [-2, 4, 9, 4, -3, 4, 9, 5])
 - result: sum_positive_even_numbers() = 12

sum_positive_even_numbers('numb_1': [8, 10, 7, 2, 14, 5, 4])
 - result: sum_positive_even_numbers() = 38

sum_positive_even_numbers('numb_2')
 - result: sum_positive_even_numbers() = 6492

sum_positive_even_numbers('numb_3')
 - result: sum_positive_even_numbers() = 80012
```


#### 4.3 *sum_recursive()*

Results for *sum_recursive()* are the same as for *sum()*.


#### 4.4 *find_first()*

Results:

```
find_first('numbers': [-2, 4, 9, 4, -3, 4, 9, 5])
 - result: find_first(x=4)  =  1
 - result: find_first(x=-3) =  4
 - result: find_first(x=1)  = -1
```


#### 4.5 *find_last()*

Results:

```
find_last('numbers': [-2, 4, 9, 4, -3, 4, 9, 5])
 - result: find_last(x=4)  =  5
 - result: find_last(x=-3) =  4
 - result: find_last(x=1)  = -1
```


#### 4.6 *find_all()*

Results:

```
find_all('numbers': [-2, 4, 9, 4, -3, 4, 9, 5])
 - result: find_all(x=4)  = [1, 3, 5]
 - result: find_all(x=-3) = [4]
 - result: find_all(x=1)  = []
```


#### 4.7 *find_sums()*

Results:

```
find_sums('numb_1': [8, 10, 7, 2, 14, 5, 4])
 - sum=10, result: [(2,8)]
 - sum=12, result: [(5,7), (4,8), (2,10)]   (in any order)
 - sum=15, result: [(7,8), (5,10)]          (in any order)
```


#### 4.8 *find_all_sums()*

Results:

```
find_all_sums('numb_1': [8, 10, 7, 2, 14, 5, 4])
 - sum=10, result: [[10], [2, 8]]                           (in any order)
 - sum=12, result: [[4, 8], [2, 10], [5, 7]]                (in any order)
 - sum=14, result: [[14], [4, 10], [2, 4, 8], [2, 5, 7]]    (in any order)
 - sum=15, result: [[7, 8], [5, 10], [2, 5, 8]]             (in any order)
 - sum=20, result: [[2, 8, 10], [5, 7, 8], [2, 4, 14]]      (in any order)
```

Weitere Beispiele:

```
find_all_sums('numb_2'), sum=1000
 - result: [
    - [226, 774],
    - [754, 87, 7, 27, 125],
    - [7, 27, 636, 125, 205],
    - [7, 651, 27, 125, 190],
    - [7, 27, 125, 205, 190, 446]
   ], solutions: 5
```

```
find_all_sums('numb_2'), sum=999
 - result: [
    - [27, 972],
    - [226, 773],
    - [170, 190, 639],
    - [371, 87, 541],
    - [226, 27, 541, 205],
    - [163, 170, 125, 541],
    - [163, 170, 27, 639],
    - [163, 7, 190, 639],
    - [226, 371, 170, 27, 205],
    - [226, 371, 7, 205, 190],
    - [226, 371, 87, 125, 190],
    - [226, 163, 371, 87, 27, 125],
    - [226, 163, 371, 7, 27, 205]
   ], solutions: 13
```


#### 4.8a *find_all_sums()* - XL Solution Space 2^30

Extend array `numb_2` by two numbers: +`225` and +`463` (change comments).

```c++
/*
 * Larger set of 24 numbers, no negatives, no duplicates.
 */
const vector<int> numb_2 = {   // n=2, 24 numbers
    371,  682,  446,  754,  205,  972,  600,  163,  541,  672,
        27,  170,  226,    7,  190,  639,   87,  773,  651,  370,
    125,  774,  903,  636//,225,  463,  286,  569,  384,    9,
}; // add more numbers to find more  solutions
```

Repeat invocation from 4.1.
With the two added numbers, 17 solutions are found (13 before).

```
find_all_sums('numb_2'), sum=999
 - result: [
    - [225, 774],
    - [27, 972],
    - [226, 773],
    - [371, 87, 541],
    - [170, 190, 639],
    - [163, 7, 190, 639],
    - [226, 27, 541, 205],
    - [163, 170, 125, 541],
    - [225, 226, 7, 541],
    - [163, 170, 27, 639],
    - [226, 371, 170, 27, 205],
    - [226, 371, 7, 205, 190],
    - [225, 226, 371, 7, 170],
    - [226, 371, 87, 125, 190],
    - [226, 163, 371, 87, 27, 125],
    - [226, 163, 371, 7, 27, 205],
    - [225, 87, 7, 27, 190, 463]
   ], solutions: 17
```

Array `numb_2` started with 24 numbers yielding *2^24* combinations.
The solution space expands rapidely by adding numbers to `numb_2`,
doubling with each number added. After adding +`225` and +`463`,
it is *2^26*.

Adding number: +`286` yields 19 solutions from solution space *2^27*.

Adding more numbers one after another yields with +`569` (21 solutions),
+`384` (24 solutions) and +`9` (44 solutions):

```
find_all_sums('numb_2'), sum=999
 - result: [
    - [226, 773],                   - [371, 27, 125, 286, 190],
    - [27, 972],                    - [225, 226, 371, 7, 170],
    - [225, 774],                   - [226, 7, 569, 170, 27],
    - [170, 190, 639],              - [225, 370, 9, 205, 190],
    - [371, 87, 541],               - [226, 163, 371, 7, 27, 205],
    - [225, 569, 205],              - [226, 163, 371, 87, 27, 125],
    - [903, 87, 9],                 - [226, 163, 9, 125, 286, 190],
    - [226, 9, 125, 639],           - [225, 7, 9, 170, 125, 463],
    - [163, 9, 541, 286],           - [384, 7, 170, 27, 125, 286],
    - [163, 170, 27, 639],          - [384, 226, 163, 9, 27, 190],
    - [225, 226, 7, 541],           - [225, 7, 9, 27, 541, 190],
    - [163, 170, 125, 541],         - [225, 87, 7, 27, 190, 463],
    - [163, 7, 190, 639],           - [384, 226, 87, 7, 9, 286],
    - [773, 9, 27, 190],            - [7, 9, 125, 205, 190, 463],
    - [226, 27, 541, 205],          - [9, 170, 27, 125, 205, 463],
    - [163, 87, 286, 463],          - [225, 87, 9, 27, 205, 446],
    - [384, 27, 125, 463],          - [384, 226, 87, 7, 170, 125],
    - [226, 371, 87, 125, 190],     - [225, 370, 163, 9, 27, 205],
    - [226, 371, 170, 27, 205],     - [225, 371, 7, 9, 170, 27, 190],
    - [226, 371, 7, 205, 190],      - [163, 7, 9, 27, 125, 205, 463],
    - [163, 371, 9, 170, 286],      - [370, 226, 7, 9, 170, 27, 190],
    - [225, 87, 9, 651, 27],        - [384, 87, 7, 9, 170, 27, 125, 190]
   ], solutions: 44
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

Special algorithms such as
[branch & bound](https://en.wikipedia.org/wiki/Branch_and_bound)
can be used to find solutions by "cutting branches" of combinations
that cannot yield a solution, e.g. when sum is exceeded.

Although only 10 solutions are found from `numb_3` of numbers
yielding sum=999, the space to explore is huge *2^63*.

```
find_all_sums('numb_3'), sum=999
 - result: [
    - [521, 463, 15],
    - [500, 36, 463],
    - [36, 7, 493, 463],
    - [498, 408, 78, 15],
    - [498, 23, 463, 15],
    - [23, 440, 521, 15],
    - [500, 36, 23, 440],
    - [36, 485, 463, 15],
    - [36, 23, 7, 440, 493],
    - [36, 485, 23, 440, 15]
   ], solutions: 10
```

Searching for `sum=996`, `sum=500` and `sum=100`

```
find_all_sums('numb_3')
 - sum=996, result: [
    - [440, 78, 463, 15],
    - [498, 36, 7, 440, 15]
   ]                                                solutions: 2
 - sum=500, result: [[500], [7, 493], [485, 15]]    solutions: 3
 - sum=100, result: [[7, 78, 15]]                   solutions: 1
```

Searching for larger sum-values increases search time since shorter
branches can be cut.

```
sum       solutions found      time
-----------------------------------
2000      38                7,2 sec
2100      18               13,7 sec
2200      37               20,4 sec
2300      64               18,6 sec
2400      73               51,6 sec
2500      52               1:53 min
```
