#include <iostream>
#include "numbers.h"
#include "ostream_helper.h"
using namespace std;

namespace Numbers {

    // numbers with duplicates and negative numbers
    const int numbers_arr[]   = {-2, 4, 9, 4, -3, 4, 9, 5};

    const vector<int> &numbers = {-2, 4, 9, 4, -3, 4, 9, 5};

    // no duplicates and no negative numbers
    const vector<int> &numb_1 = {8, 10, 7, 2, 14, 5, 4};

    const vector<int> &numb_2 = {   // n=2, 24 numbers
        371,  682,  446,  754,  205,  972,  600,  163,  541,  672,
         27,  170,  226,    7,  190,  639,   87,  773,  651,  370,
        125,  774,  903,  636//,225,  463,  286,  569,  384,    9,
    }; // add more numbers to find more  solutions

    const vector<int> &numb_3 = {   // n=3, 63 numbers
        799, 2377,  936, 3498, 1342,  493, 1635, 4676,  1613, 3851,
        1445, 4506, 3346,    7, 2141, 2064, 1491,  908,   78, 3325,
        1756, 3691,   23, 1995, 1800,   15, 2784, 4305,   36, 2532,
        4292, 4802, 2522, 4183, 3261, 2610,  803, 2656,  498, 1668,
        2038, 2194,  440,  463, 4047, 4235, 3931,  756,  521, 4042,
        3302,  485, 1002,  408, 4691, 3387, 3104, 3658, 2241, 4382,
        1220, 3656,  500,
    };


    /**
     * main() function in Demo:: namespace that prints command line arguments.
     *
     * @param argc number of command line arguments.
     * @param argv vector with command line arguments.
     * @return 0 for successfull execution or other exit code for failure.
     */
    int main(int argc, char *argv[]) {
        cout << "Numbers::main() in numbers.cpp:" << endl;

        // Aufgabe 1:
        int res1 = sum(numbers);
        cout << numbers << " --> sum: " << res1 << endl;

        // Aufgabe 2:
        int res2 = sum_positive_even_numbers(numbers);
        cout << numbers << " --> sum_positive_even_numbers: " << res2 << endl;

        // Aufgabe 3:
        int res3 = sum_recursive(0, numbers);
        cout << numbers << " --> sum_no_loop: " << res3 << endl;

        // Aufgabe 4:
        int res4 = find_first(4, numbers);
        cout << numbers << " --> find_first: " << res4 << endl;

        // Aufgabe 5:
        int res5 = find_last(4, numbers);
        cout << numbers << " --> find_first: " << res5 << endl;

        // Aufgabe 6:
        vector<int> res6 = find_all(4, numbers);
        cout << numbers << " --> find_all: " << res6 << endl;

        // Aufgabe 7:
        int sum=12;
        vector<pair<int, int>> res7 = find_sums(12, numb_1);
        cout << numb_1 << " --> find_sums(" << sum << "): " << res7 << endl;
        //
        // avoid duplicates and mirror pairs
        const vector<int> &numb_11 = {8, 10, 7, 2, 10, 5, 4, 9, 3, 3, 9};
        res7 = find_sums(sum, numb_11);
        cout << numb_11 << " --> find_sums(" << sum << "): " << res7 << endl;

        // Aufgabe 8:
        set<set<int>> res8 = find_all_sums(14, numbers);
        cout << numbers << " --> find_all_sums: " << res8 << endl;

        return EXIT_SUCCESS;
    }
}