#include "main.h"

#ifdef NUMBERS
#include "numbers.h"
#endif
#ifdef DEMO
#include "demo.h"
#endif


/*
 * Definitions (data)
 */
call_table_t call_table[] {
    {"main", &main},
#ifdef DEMO
    {"demo", &Demo::main},
#endif
#ifdef NUMBERS
    {"nu", &Numbers::main},
    {"numbers", &Numbers::main},
#endif
};

/**
 * main() function as main entry point of program execution.
 *
 * @param argc number of command line arguments.
 * @param argv vector with command line arguments.
 * @return 0 for successfull execution or other value for failure.
 */
int main(int argc, char *argv[]) {
    const string arg1 = argc > 1? argv[1] : "";
    const int ct_len = sizeof(call_table)/sizeof(call_table_t);
    if(arg1.length()==0 && ct_len > 1) {
        // if no arg1 is provided, call last function from call_table
        return call_table[ct_len-1].func_ptr(argc-1, argv);
    }
    for(int i=ct_len-1; i >= 0; i--) {
        if(arg1.compare(call_table[i].arg)==0) {
            for(int i=1; i < argc-1; i++) {
                argv[i] = argv[i+1];    // shift argv[] one left
            }
            if(arg1 != "main") {
                // call function from call_table matching arg1
                return call_table[i].func_ptr(argc-1, argv);
            }
        }
    }
    // no matching arg found in call_table
    cout << "Hello main.cpp" << endl;
    return EXIT_SUCCESS;    // return to c++ run-time library
}