#include <iostream>
using namespace std;

namespace Shape {

int main(int argc, const char * argv[]) {
    std::string name = "John";
    cout << "Hello, C++ World!" << endl;
    cout << "    /|" << endl;
    cout << "   / |" << endl;
    cout << "  /  |" << endl;
    cout << " /   |" << endl;
    cout << "/____|" << endl;

    for (int i = 0; i < argc; ++i) {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }
    return 0;
}
} // namespace Shape
