#include <iostream>
using namespace std;

// data definitons (memory is allocated)
const int   num_arr[] = {-2, 4, 9, 4, -3, 4, 9, 5};

// function declarations (can be used, but no implementation)
int sum(const int numbers[], const int len);


int main() {
    int sum_arr = sum(num_arr, 8);
    //
    std::cout << "Hello Numbers!" << endl;
    std::cout << "sum_arr="  << sum_arr  << endl;
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
