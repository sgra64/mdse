#include "numbers.h"
#include <iostream>

namespace NumbersNS {
using namespace collections;

/*
 * forward declarations
 */
pset<int> &psetRecursive(const set<int> &numbers);
pset<int> &pset64bit(const set<int> &numbers);

template<typename... Args>
std::string format(const char* fmt, Args... args);
// 
template <typename T>
std::ostream& prettyprint(pset<T>& set, std::ostream& os);
std::ostream& operator<<(std::ostream& os, const Numbers impl) { return os; }
// 
Numbers& sum_ab_tests(Numbers &impl, std::ostream& os);
Numbers& sum_numbers_tests(Numbers &impl, std::ostream& os);
Numbers& sum_positive_even_numbers_tests(Numbers &impl, std::ostream& os);
Numbers& all_pairs_tests(Numbers &impl, std::ostream& os);
Numbers& all_sums_tests(Numbers &impl, std::ostream& os);
Numbers& all_sums_extended_tests(Numbers &impl, std::ostream& os);


/*
 * Some numbers data sets.
 */
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


int main(int argc, const char *argv[]) {
    // 
    std::ostream& os = std::cout;
    os << "--- Numbers examples:" << std::endl;
    // 
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
    // os << sum_ab_tests(impl, os) << std::endl;
    // os << sum_numbers_tests(impl, os) << std::endl;
    // os << sum_positive_even_numbers_tests(impl, os) << std::endl;
    // os << all_pairs_tests(impl, os) << std::endl;
    // os << all_sums_tests(impl, os) << std::endl;
    // os << all_sums_extended_tests(impl, os) << std::endl;
    // 

    return 0;
}


Numbers& sum_ab_tests(Numbers &impl, std::ostream& os) {
    int a=10, b=12, sum=impl.sum(a, b);
    os << format("- sum(%d, %d) --> %d", a, b, sum) << std::endl;
    // 
    a=999999; b=1; sum=impl.sum(a, b);
    os << format("- sum(%d, %d) --> %d", a, b, sum) << std::endl;
    // 
    a=-999999; b=-1; sum=impl.sum(a, b);
    os << format("- sum(%d, %d) --> %d", a, b, sum) << std::endl;
    // 
    return impl;
}

Numbers& sum_numbers_tests(Numbers &impl, std::ostream& os) {
    int sum=impl.sum(numbers);
    os << format("- sum(numbers) --> %d", sum) << std::endl;
    // 
    sum=impl.sum(numb_1);
    os << format("- sum(numb_1) --> %d", sum) << std::endl;
    // 
    sum=impl.sum(numb_2);
    os << format("- sum(numb_2) --> %d", sum) << std::endl;
    // 
    sum=impl.sum(numb_3);
    os << format("- sum(numb_3) --> %d", sum) << std::endl;
    // 
    return impl;
}

Numbers& sum_positive_even_numbers_tests(Numbers &impl, std::ostream& os) {
    int sum=impl.sum_positive_even(numbers);
    os << format("- sum_positive_even(numbers) --> %d", sum) << std::endl;
    // 
    sum=impl.sum_positive_even(numb_1);
    os << format("- sum_positive_even(numb_1) --> %d", sum) << std::endl;
    // 
    sum=impl.sum_positive_even(numb_2);
    os << format("- sum_positive_even(numb_2) --> %d", sum) << std::endl;
    // 
    sum=impl.sum_positive_even(numb_3);
    os << format("- sum_positive_even(numb_3) --> %d", sum) << std::endl;
    // 
    return impl;
}

Numbers& all_pairs_tests(Numbers &impl, std::ostream& os) {
    // 
    int target_sum=10; auto pairs = impl.all_pairs(numb_1, target_sum);

    os << format("- all_pairs(numb_1, %d) --> ", target_sum) << pairs << std::endl;
    // 
    target_sum=12; pairs = impl.all_pairs(numb_1, target_sum);
    os << format("- all_pairs(numb_1, %d) --> ", target_sum) << pairs << std::endl;
    // 
    target_sum=15; pairs = impl.all_pairs(numb_1, target_sum);
    os << format("- all_pairs(numb_1, %d) --> ", target_sum) << pairs << std::endl;
    // 
    target_sum=500; pairs = impl.all_pairs(numb_3, target_sum);
    os << format("- all_pairs(numb_3, %d) --> ", target_sum) << pairs << std::endl;
    // 
    target_sum=5000; pairs = impl.all_pairs(numb_3, target_sum);
    os << format("- all_pairs(numb_3, %d) --> ", target_sum) << pairs << std::endl;
    // 
    return impl;
}

Numbers& all_sums_tests(Numbers &impl, std::ostream& os) {
    // 
    int target_sum=10; pset<int> &sums = impl.all_sums(numb_1, target_sum);
    os << format("- all_sums(numb_1, %d) --> ", target_sum) << sums << format("\t\t--> %d solutions", sums.size()) << std::endl;
    // 
    target_sum=12; sums = impl.all_sums(numb_1, target_sum);
    os << format("- all_sums(numb_1, %d) --> ", target_sum) << sums << format("\t\t--> %d solutions", sums.size()) << std::endl;
    // 
    target_sum=14; sums = impl.all_sums(numb_1, target_sum);
    os << format("- all_sums(numb_1, %d) --> ", target_sum) << sums << format("\t\t--> %d solutions", sums.size()) << std::endl;
    // 
    target_sum=15; sums = impl.all_sums(numb_1, target_sum);
    os << format("- all_sums(numb_1, %d) --> ", target_sum) << sums << format("\t\t--> %d solutions", sums.size()) << std::endl;
    // 
    target_sum=20; sums = impl.all_sums(numb_1, target_sum);
    os << format("- all_sums(numb_1, %d) --> ", target_sum) << sums << format("\t\t--> %d solutions", sums.size()) << std::endl;
    // 
    return impl;
}

Numbers& all_sums_extended_tests(Numbers &impl, std::ostream& os) {
    // 
    int target_sum=999; pset<int> &sums = impl.all_sums(numb_2, target_sum);
    os << format("- all_sums(numb_2, %d) --> ", target_sum);
    prettyprint(sums, os) << format(" --> %d solutions\n\n", sums.size());
    // 
    target_sum=1000; sums = impl.all_sums(numb_2, target_sum);
    os << format("- all_sums(numb_2, %d) --> ", target_sum);
    prettyprint(sums, os) << format(" --> %d solutions\n\n", sums.size());
    // 
    target_sum=999; sums = impl.all_sums(numb_3, target_sum);
    os << format("- all_sums(numb_3, %d) --> ", target_sum);
    prettyprint(sums, os) << format(" --> %d solutions\n\n", sums.size());
    // 
    target_sum=1000; sums = impl.all_sums(numb_3, target_sum);
    os << format("- all_sums(numb_3, %d) --> ", target_sum);
    prettyprint(sums, os) << format(" --> %d solutions\n\n", sums.size());
    // 
    return impl;
}

template <typename T>
std::ostream& prettyprint(pset<T>& set, std::ostream& os) {
    int size = set.size();
    os << "{" << std::endl;
    for (auto it = set.begin(); it != set.end(); ++it) {
        auto next = it;
        ++next;
        os << "    " << *it;
        if (next != set.end()) {
            os << ",";
        }
        os << std::endl;
    }
    return os << "  }";
}

template<typename... Args>
std::string format(const char* fmt, Args... args) {
    // 
    size_t size = snprintf(nullptr, 0, fmt, args...);
    std::string buf;
    buf.reserve(size + 1);
    buf.resize(size);
    snprintf(&buf[0], size + 1, fmt, args...);
    return buf;
}

} // NumbersNS
