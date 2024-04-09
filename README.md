## A4: Hello World

This branch has the code `hello.cpp` in directory `src` to run
in a VS Code *dev container*.

[*"Hello World"*](https://en.wikipedia.org/wiki/%22Hello,_World!%22_program)
is a program written by
[Brian Kerngihan](https://en.wikipedia.org/wiki/Brian_Kernighan), creator
of the
[C](https://en.wikipedia.org/wiki/C_(programming_language))
programming language with
[Dennis Ritchie](https://en.wikipedia.org/wiki/Dennis_Ritchie) and
[Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson) - the creators of the
[Unix](https://en.wikipedia.org/wiki/Unix) operating system (1971), which is
the base of most common operating systems used today (MacOS, iOS, Android, 
Linux, ...).

```c++
#include <iostream>
using namespace std;

int main() {
    std::cout << "Hello World!" << endl << endl;
    return 0;
}
```

Output:

```
Hello World!
```