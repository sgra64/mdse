<!-- check-out single branch from repo:
        git clone -b B12 --single-branch https://github.com/sgra64/mdse.git
 -->

# Assignment B1: C-Data


Assignment B1 demonstrates the use of data structures by the example of a
list type that stores consecutively addressable elements. The type dynamically
expands as elements are added.

```c
/**
 * Data structure of a list type with consecutively addressable elements
 * that dynamically expands as elements are added.
 * List elements are of a simple type (int) or are sub-lists.
 * 
 * Examples:
 *  - [1, 2, 3] (simple list) or [[4, 5], [6]] nested list with sub-lists.
 */
struct list {
    int cap;            // capacity
    int len;            // current length
    int is_simple;      // is simple list, e.g. [1, 2, 3] usind idata[]
    union {
        int (*idata)[];             // pointer to array of int
        struct list *(*ldata)[];    // pointer to struct list *
    } data;
};
```

Methods of the type are:

```c

/**
 * Create simple, emtpy list.
 */
extern struct list *list_create();

/**
 * Create simple list initialized with values.
 */
extern struct list *list_from_values(int argn, int values[]);

/**
 * Create empty list that can store sub-lists.
 */
extern struct list *list_with_sublists();

/**
 * Create new list as copy of list.
 */
extern struct list *list_copy(struct list *list);

/**
 * Add simple element to list.
 */
extern struct list *list_add(struct list *list, int e);

/**
 * Add list to list with sub-lists.
 */
extern struct list *list_add_list(struct list *list, struct list *e);

/**
 * Print list.
 */
extern void list_print(struct list *list);
```


&nbsp;

Steps

1. [Setup](#1-setup)

1. [Create Source Code](#2-create-source-code)

1. [Build and Run](#3-build-and-run)



&nbsp;
## 1. Setup

Create a project folder named `b1-data` and within a file named `.gitignore`:

```
#------------------------------------------------------------------------------
# .gitignore contains patterns of files and directories to be ignored by git.
# #
# see: https://www.atlassian.com/git/tutorials/saving-changes/gitignore
# example: https://github.com/github/gitignore/blob/master/Java.gitignore
#------------------------------------------------------------------------------

# allow README.md to be deleted in local project
README.md

# Compiled Object files
*.o
*.obj

# Compiled Dynamic libraries
*.so
*.dll

# Compiled Static libraries
*.a
*.lib

# Executables
*.exe
*.out
```

Initialize the project as a *git* project:

```sh
git add .gitignore                  # stage '.gitignore' file
git commit -m "add .gitignore"      # commit '.gitignore' file

git tag t1                          # tag commit with 't1'

git log --oneline                   # show commit log/history
```



&nbsp;

## 2. Create Source Code

Create source files:

- `list.h` (from content above) and [list.c](list.c),

- create main file `main.c`,

- create `makefile`

from:

`main.c`:

```c
#include <stdio.h>      // printf
#include "list.h"


int main() {
    printf("Hello World!\n");
    //
    int d1[] = {1, 2, 3};
    int d2[] = {4, 5, 6, 7, 8, 9};
    struct list *l1 = list_from_values(sizeof(d1)/sizeof(int), d1);
    struct list *l2 = list_from_values(sizeof(d2)/sizeof(int), d2);
    struct list *lsub = list_with_sublists();
    ;
    list_print(l1);
    printf("\n");
    //
    list_print(l2);
    printf("\n");
    //
    list_print(
        list_add_list(
            list_add_list(lsub, l1), l2)
    );
    printf("\n");
    return 0;
}
```

&nbsp;

Read about C and C++'s build tool [*makefile*](https://makefiletutorial.com).

`Makefile`:

```c
# simple makefile following instructions in
# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#
# a more comprehensive survey of 'make' and 'makefile' is
# https://makefiletutorial.com/


# rule to make .o files from .c files
%.o: %.c
        $(CC) -c $< $(CFLAGS) -o $@

# main goal
all: main

# link $(OBJ) to build 'main' executable file
main: main.o list.o
        $(CC) -o $@ $^ $(CFLAGS) $(LIBS)

main.o: main.c list.h
list.o: list.h list.c


# phony goals are used for commands and ignore files of the same name
.PHONY: all clean

clean:
        rm -f *.o main main.exe
```



&nbsp;

The project should have the following content:

```sh
ls -la                  # show project content
```
```
total 44
drwxr-xr-x 1 svgr2 Kein    0 Apr 17 09:50 .
drwxr-xr-x 1 svgr2 Kein    0 Apr 17 09:29 ..
drwxr-xr-x 1 svgr2 Kein    0 Apr 17 09:50 .git
-rw-r--r-- 1 svgr2 Kein  591 Apr  2 00:31 .gitignore
-rw-r--r-- 1 svgr2 Kein 4244 Apr 17 09:45 list.c
-rw-r--r-- 1 svgr2 Kein 1358 Apr 17 09:42 list.h
-rw-r--r-- 1 svgr2 Kein  565 Apr 17 09:48 main.c
-rw-r--r-- 1 svgr2 Kein  571 Apr 17 09:50 makefile
```



&nbsp;
## 3. Build and Run


```sh
make -n                 # test-run the project
```
```
cc -c main.c  -o main.o
cc -c list.c  -o list.o
cc -o main main.o list.o
```

Build the project

```sh
make                    # build the project
ls -la
```
```
total 124
drwxr-xr-x 1     0 Apr 17 10:04 ./
drwxr-xr-x 1     0 Apr 17 09:29 ../
drwxr-xr-x 1     0 Apr 17 09:50 .git/
-rw-r--r-- 1   591 Apr  2 00:31 .gitignore
-rw-r--r-- 1  4244 Apr 17 09:45 list.c
-rw-r--r-- 1  1358 Apr 17 09:42 list.h
-rw-r--r-- 1  2961 Apr 17 10:04 list.o
-rw-r--r-- 1   565 Apr 17 09:48 main.c
-rwxr-xr-x 1 69899 Apr 17 10:04 main.exe*
-rw-r--r-- 1  1335 Apr 17 10:04 main.o
-rw-r--r-- 1   571 Apr 17 09:50 makefile
```

Run the *main* program:

```sh
main                    # run the main program
```
```
Hello World!
[1, 2, 3]
[4, 5, 6, 7, 8, 9]
[[1, 2, 3], [4, 5, 6, 7, 8, 9]]
```

Commit the project in steps with:

1. `makefile` (commit) followed by

1. `*.[ch]` files.

Show the commit log:

```sh
git log --oneline                   # show commit log/history
```
