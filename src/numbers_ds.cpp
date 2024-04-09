#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

// data definitons (memory is allocated)
const int   num_arr[] = {-2, 4, 9, 4, -3, 4, 9, 5};
const vector<int> num_vec = {-2, 4, 9, 4, -3, 4, 9, 5};
const list<int> num_list = {-2, 4, 9, 4, -3, 4, 9, 5};
const set<int> num_set = {-2, 4, 9, 4, -3, 4, 9, 5};

// function declarations (can be used, but no implementation)
int sum(const int numbers[], const int len);
int sum(const vector<int>& numbers);
int sum(const list<int>& numbers);
int sum(const set<int>& numbers);


int main() {
    int sum_arr = sum(num_arr, 8);
    int sum_vec = sum(num_vec);
    int sum_list = sum(num_list);
    int sum_set = sum(num_set);
    //
    std::cout << "Hello Numbers_DS (data structures)!" << endl;
    std::cout << "sum_arr="  << sum_arr  << endl;
    std::cout << "sum_vec="  << sum_vec  << endl;
    std::cout << "sum_list=" << sum_list << endl;
    std::cout << "sum_set="  << sum_set << endl;
    std::cout << endl;
    return 0;
}

// function definitions (implementations of declared functions)
int sum(const int numbers[], const int len) {
    int res = 0;
    for(int i=0; i < len; i++) {
        res += numbers[i];
    }
    return res;
}

int sum(const vector<int>& numbers) {
    int res = 0;
    for(const int& n : numbers) {
        res += n;
    }
    return res;
}

int sum(const list<int>& numbers) {
    int res = 0;
    for(const int& n : numbers) {
        res += n;
    }
    return res;
}

int sum(const set<int>& numbers) {
    int res = 0;
    for(const int& n : numbers) {
        res += n;
    }
    return res;
}
