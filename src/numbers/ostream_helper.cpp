#include <vector>
#include <iostream>
#include <iomanip>
#include "numbers.h"
using namespace std;

namespace Numbers {

    /**
     * ostream print helper for pair<int, int>.
     * @param out ostream on left-side of << operator
     * @param p pair to print
     */
    ostream& operator<< (std::ostream& out, const pair<int, int> &p) {
        return out << "[" << p.first << ", " << p.second << "]";
    }

    /**
     * ostream print helper for vector<int>.
     * @param out ostream on left-side of << operator
     * @param v vector to print
     */
    ostream& operator<< (std::ostream& out, const vector<int> &v) {
        out << "[";
        // C++20: std::ranges::copy(v, std::ostream_iterator<int>(out, ", "));
        for (long unsigned i=0; i < v.size(); i++) {
            if(i > 0 && i % 10 == 0) {
                cout << endl << " ";
            }
            if(v.size() > 12) {
                cout << std::setw(4);   // right-align numbers to width 4
            }
            cout << v[i] << (i < v.size()-1? ", " : "");
        }
        return out << "]";
    }

    /**
     * ostream print helper for vector<pair<int, int>>.
     * @param out ostream on left-side of << operator
     * @param v vector to print
     */
    ostream& operator<< (std::ostream& out, const vector<pair<int, int>> &v) {
        out << "[";
        // C++20: std::ranges::copy(v, std::ostream_iterator<int>(out, ", "));
        for (long unsigned i=0; i < v.size(); i++) {
            if(i > 0 && i % 10 == 0) {
                cout << endl << " ";
            }
            cout << v[i] << (i < v.size()-1? ", " : "");
        }
        return out << "]";
    }

    /**
     * ostream print helper for set<int>.
     * @param out ostream on left-side of << operator
     * @param s set to print
     */
    ostream& operator<< (std::ostream& out, const set<int> &s)  {
        out << "{";
        unsigned int i = 0;
        for(const int &n : s) {
            cout << n << (i++ < s.size()-1? ", " : "");
        }
        return out << "}";
    }

    /**
     * ostream print helper for set<set<int>>.
     * @param out ostream on left-side of << operator
     * @param s set to print
     */
    ostream& operator<< (std::ostream& out, const set<set<int>> &s) {
        out << "{";
        bool ml = s.size() > 5;     // multi-line output for larger sets
        unsigned int i = 0;
        for(const set<int> &n : s) {
            cout << (ml? "\n  - " : "") << n << (i++ < s.size()-1? ", " : "");
        }
        return out << (ml? "\n}" : "}");
    }
}