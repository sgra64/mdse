#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string.h>

/*
 * Macro definitions and switches:
 */
#define NUMBERS
#define DEMO

/*
 * Declarations:
 * - to use std namespace (to avoid std:: for string, cout, endl).
 * - of a type of a function pointer with signature of the main() function.
 * - of a type of a structure matching a string arg to a function pointer.
 * - of the main() function.
 */
using namespace std;

typedef int (*func_ptr_t)(int argc, char *argv[]);

/*
 * The command line argument matching 'arg' defines the function to call.
 * For example: 'playground demo' calls the function matching arg='demo'.
 */
struct call_table_t {
    string arg;
    func_ptr_t func_ptr;
};

int main(int argc, char *argv[]);

#endif // MAIN_H