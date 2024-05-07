#include <iostream>
#include <string.h>
#include "demo.h"
using namespace std;

namespace Demo {

  /**
   * main() function in Demo:: namespace that prints command line arguments.
   *
   * @param argc number of command line arguments.
   * @param argv vector with command line arguments.
   * @return 0 for successfull execution or other exit code for failure.
   */
  int main(int argc, char *argv[]) {
    cout << "Demo::main() in demo.cpp:" << endl;
    //
    cout << "Command line arguments: argc=" << argc << ", ";
    cout << "argv[0.." << argc-1 << "]: ";
    for(int i=0; i < argc; i++) {
        string arg = argv[i];
        if(i==0) {
            // remove path from name of executable program for $0 argument
            size_t found = arg.find_last_of("[\\/]");
            arg = found==string::npos? arg : arg.substr(found+1);
        }
        cout << "\'" << arg << "\' ";
    }
    cout << endl;
    //
    return EXIT_SUCCESS;
  }
}