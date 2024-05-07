#ifndef OSTREAM_HELPER_H
#define OSTREAM_HELPER_H
#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

namespace Numbers {

    /**
     * ostream print helper for pair<int, int>.
     * @param out ostream on left-side of << operator
     * @param p pair to print
     */
    ostream& operator<< (std::ostream& out, const pair<int, int> &p);

    /**
     * ostream print helper for vector<int>.
     * @param out ostream on left-side of << operator
     * @param v vector to print
     */
    ostream& operator<< (std::ostream& out, const vector<int> &v);

    /**
     * ostream print helper for vector<pair<int, int>>.
     * @param out ostream on left-side of << operator
     * @param v vector to print
     */
    ostream& operator<< (std::ostream& out, const vector<pair<int, int>> &v);

    /**
     * ostream print helper for set<int>.
     * @param out ostream on left-side of << operator
     * @param s set to print
     */
    ostream& operator<< (std::ostream& out, const set<int> &s);

    /**
     * ostream print helper for set<set<int>>.
     * @param out ostream on left-side of << operator
     * @param s set to print
     */
    ostream& operator<< (std::ostream& out, const set<set<int>> &s);

}
#endif // OSTREAM_HELPER_H