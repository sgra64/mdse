#include <iostream>
#include <vector>
#include "collections.h"
using namespace std;
using namespace collections;

namespace Shape {
    extern int main(int argc, const char *argv[]);
}


int main(int argc, const char *argv[]) {
    // 
    cout << "Hello main.cpp" << endl;
    // 
    cout << "\nDraw shape example:" << endl;
    Shape::main(argc, argv);
    // 
    cout << "\nCollections example:" << endl;
    collections::list<int> nlist = {4, 3, 2, 2, 2, 1};
    collections::set<int> nset = {3, 2, 1};
    // collections::set<int> nset = {8, 10, 7, 2, 14, 4};
    // 
    // nlist.insertAt(4, 7);
    // nlist << 7 << 7 << 7;
    // nset << 2 << 2 << 7;
    // nset << 7;
    // 
    cout << "nlist:\t" << nlist << endl;
    cout << "nset:\t" << nset << endl;
    // 
    int sum = 0;
    for (const auto& e : nlist) {
        sum += e;
    }
    cout << nlist << "\t--> sum: " << sum << endl;

    sum = 0;
    for (const auto& e : nset) {
        sum += e;
    }
    cout << nset << "\t--> sum: " << sum << endl;
    // 
    return 0;
}

#include "collections.tpp"
