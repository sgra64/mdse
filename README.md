<!-- check-out single branch from repo:
        git clone -b G1 --single-branch https://github.com/sgra64/mdse.git
 -->

# Assignment G1: Graphs (shortest path)

A *[Graph](https://en.wikipedia.org/wiki/Graph_theory)*
is a set of *nodes* (vertices) and *edges* connecting nodes G = { n ∈ N, e ∈ E }.
A *weighted Graph* has *weights* associated with egdes.

The task is to find the *"shortest path"* between a *start node* `'S'` and
an *end node* `'E'`. The attribute *"shortest"* refers to the minimum added weight
of edges. The problem has many useful applications, e.g. in navigation systems.

<img src="https://raw.githubusercontent.com/sgra64/mdse/markup/g1-graphs/graph_1.jpg" alt="drawing" width="800"/>

*Edsger W. Dijkstra* (1930-2003,
[bio](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra))
was a Dutch computer scientist, software engineer, professor of Computer Science
at the Univerity of Austin, Texas who developed
[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
to find a shortest
path in an undirected, weighted graph. He received the
[Turing Award](https://en.wikipedia.org/wiki/Turing_Award)
for this and numerous other contributions in computer science in 1972.

<img src="https://upload.wikimedia.org/wikipedia/commons/d/d9/Edsger_Wybe_Dijkstra.jpg" alt="drawing" width="100"/>

*Edsger W. Dijkstra* (1930-2003,
[bio](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra))
was a Dutch computer scientist, software engineer, professor of Computer Science
at the Univerity of Austin, Texas who developed
[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
to find a shortest
path in an undirected, weighted graph. He received the
[Turing Award](https://en.wikipedia.org/wiki/Turing_Award)
for this and numerous other contributions in computer science in 1972.

The algorithm was used in a Bachelor thesis,
[Steffen Ansorge](https://www.linkedin.com/in/steffenansorge):
*"Planning and development of a system for route planning with unreliable position
data of intermediate stops"*,
[.pdf](https://drive.google.com/file/d/1vceT1_HE0IxMuiheIbkkzwUEKi106gMX)
at TIER to optimize scooter pickup routes for recharging.


&nbsp;

## Content

1. [Setup](#1-setup)

2. [Data Modeling](#2-data-modeling)

3. [Shortest-Path Algorithm](#3-shortest-path-algorithm)


&nbsp;

## 1. Setup

Code for the project is distributed through branch
[G1-graphs](https://github.com/sgra64/mdse/tree/G1-graphs)
in the code repository.

Setup will integrate (merge) this branch into your project using the
[git](https://en.wikipedia.org/wiki/Git) source code control system.

You should have `src` files in the project that can be shown in the
(dev-container) terminal:

```sh
find src                    # show current source files in dev-container
```

Output:

```
src
src/numbers
src/numbers/ostream_helper.h
src/numbers/numbers.h
src/numbers/numbers_functions.cpp
src/numbers/numbers.cpp
src/numbers/ostream_helper.cpp
src/demo
src/demo/demo.h
src/demo/demo.cpp
src/main.h
src/main.cpp
```

`makefile` only has dependencies for `numbers` and `demo`.

*"Integration"* (merge) of code means that new files are added from the source
and *modifications* are made to existing files, e.g. `graphs` dependencies are
added to `makefile`. Therefore, *merge* is not just a copy. Conflicts may occur
that need to be resolved.

Following steps will put the project under `git`-control (if not), add the link
to the remote source of the branch to be added, load (fetch) and merge it into
the current state of the project.

```sh
[ -d .git ] || git init         # initialize git, if project is not yet under git control

# commit all source files
git status                      # show status of project directory (working tree)

git add .* README.md makefile* src      # phase 1: stage untracked/changed files for commit
git commit -m "pre-merge commit"        # phase 2: commit (record) staged files in local git repository
git status                              # working tree is now clean (no pending changes)

# add link of remote repository under name 'mdse-repo'
git remote add mdse-repo https://github.com/sgra64/mdse.git

# fetch branch G1-graphs from the remote repository (local-branch:remote-branch)
git fetch mdse-repo G1-graphs:G1-graphs

# merge content of fetched branch into current branch (main)
git merge --allow-unrelated-histories --strategy-option theirs G1-graphs
```

Output:

```
Auto-merging .vscode/cc_objs
Auto-merging .vscode/cc_opts
Auto-merging README.md
Auto-merging makefile
Auto-merging src/main.cpp
Auto-merging src/main.h
Merge made by the 'ort' strategy.
 .vscode/cc_objs              |   2 +
 .vscode/cc_opts              |   2 +-
 README.md                    | 753 ++++++++++++++-----------------------------
 makefile                     |  12 +-
 src/graphs/graph.cpp         |  94 ++++++
 src/graphs/graph.h           |  72 +++++
 src/graphs/main.cpp          |  53 +++
 src/graphs/shortest_path.cpp |  30 ++
 src/main.cpp                 |   6 +
 src/main.h                   |   1 +
 10 files changed, 507 insertions(+), 518 deletions(-)
 create mode 100644 src/graphs/graph.cpp
 create mode 100644 src/graphs/graph.h
 create mode 100644 src/graphs/main.cpp
 create mode 100644 src/graphs/shortest_path.cpp
```

Inspecting changes from merge in project directory:

```sh
find src makefile*          # show source files in dev-container after merge
```

new files under `src/graphs` appear:

```
src
src/graphs                          <-- new src directory and files
src/graphs/shortest_path.cpp          |
src/graphs/main.cpp                   |
src/graphs/graph.cpp                  |
src/graphs/graph.h                    |
src/numbers
src/numbers/ostream_helper.h
src/numbers/numbers.h
src/numbers/numbers_functions.cpp
src/numbers/numbers.cpp
src/numbers/ostream_helper.cpp
src/demo
src/demo/demo.h
src/demo/demo.cpp
src/main.h                          <-- changed, now includes #define GRAPHS
src/main.cpp                        <-- changed
makefile                            <-- changed
makefile_addons.mk
```

`makefile` was modified in the merge to include new dependencies for `graphs`-files.
Compare differences that were made in `makefile`:

```sh
git diff HEAD~1 HEAD makefile   # compare makefile in commits before and after the merge
```

Output are the changes made by the merge:

```
diff --git a/makefile b/makefile
index b8e228a..89e5131 100644
--- a/makefile
+++ b/makefile
@@ -1,7 +1,8 @@
 # source directories with header files
 INCLUDES = \
        -Isrc/demo \
-       -Isrc/numbers               <-- previous line (no ' \')
+       -Isrc/numbers \             <-- new line (with ' \' added)
+       -Isrc/graphs                <-- added line

 # all compiled files
 OBJS = \
@@ -9,7 +10,11 @@ OBJS = \
        out/demo/demo.o \
        out/numbers/numbers.o \
        out/numbers/numbers_functions.o \
-       out/numbers/ostream_helper.o        <-- previous line (no ' \')
+       out/numbers/ostream_helper.o \      <-- new line (with ' \' added)
+       out/graphs/main.o \                 <-- added line
+       out/graphs/graph.o \                <-- added line
+       out/graphs/shortest_path.o          <-- added line
...
                                            <-- new dependencies inserted
+out/graphs/main.o:  src/graphs/graph.h src/graphs/main.cpp
+out/graphs/graph.o:  src/graphs/graph.h src/graphs/graph.cpp
+out/graphs/shortest_path.o:  src/graphs/graph.h src/graphs/shortest_path.cpp $(
GRAPH_SOLUTION_DEPS)
```

The merge created a new (post-merge) commit in the local git repository:

```sh
git diff HEAD~1 --name-status   # show differences made by the merge
git log --oneline
```

Out put shows the pre-merge and post-merge commits:

```
558b1f5 (HEAD -> main) Merge branch 'G1-graphs'
8629e2a pre-merge commit
...
```

The two commits can be compared to see the differences between the pre-
and post-merge commits.

```sh
git diff HEAD~1 --name-status   # show differences made by the merge
```

The output gives an overview of which files were added (A), modified (M)
or deleted (D, none here) by the merge:

```
M       .vscode/cc_objs                 <-- M: modified file
M       .vscode/cc_opts
M       README.md
M       makefile
A       src/graphs/graph.cpp            <-- A: new file
A       src/graphs/graph.h              <-- A: new file
A       src/graphs/main.cpp             <-- A: new file
A       src/graphs/shortest_path.cpp    <-- A: new file
M       src/main.cpp
M       src/main.h
```

The merge can be reset and the previous state of the project restore:

```sh
git reset --hard HEAD~1     # reset project to pre-merge state (pre-merge commit)
git log --oneline
```

The commit containing the merge (558b1f5) is gone and HEAD points
to the pre-merge commit:

```
8629e2a (HEAD -> main) pre-merge commit
...
```

The project directory has the pre-merge state (all changes made by the
merge are gone).

```sh
find src                    # files under: src/graphs are gone
```

Files from the merge in `src/graphs` are gone:

```
src
src/demo
src/demo/demo.cpp
src/demo/demo.h
src/main.cpp
src/main.h
src/numbers
src/numbers/numbers.cpp
src/numbers/numbers.h
src/numbers/numbers_functions.cpp
src/numbers/ostream_helper.cpp
src/numbers/ostream_helper.h
```

Of course, the merge can be repeated:

```sh
git merge --allow-unrelated-histories --strategy-option theirs G1-graphs
git log --oneline
```

The post-merge commit has been re-created (with new commit-id: c706d79):

```
c706d79 (HEAD -> main) Merge branch 'G1-graphs'
8629e2a pre-merge commit
```

The project can now be built:

```sh
make clean main.out         # build the project (main.out)
```

New files are included in the build:

```
removing main.out executable and compiled out directory
rm -rf main.out out
create out/
g++ -Isrc/demo -Isrc/numbers -Isrc/graphs -g -c -Wall -std=c++20 -c src/main.cpp -o out/main.o
create out/demo/
g++ -Isrc/demo -Isrc/numbers -Isrc/graphs -g -c -Wall -std=c++20 -c src/demo/demo.cpp -o out/demo/demo.o
create out/numbers/
g++ -Isrc/demo -Isrc/numbers -Isrc/graphs -g -c -Wall -std=c++20 -c src/numbers/numbers.cpp -o out/numbers/numbers.o
g++ -Isrc/demo -Isrc/numbers -Isrc/graphs -g -c -Wall -std=c++20 -c src/numbers/numbers_functions.cpp -o out/numbers/numbers_functions.o
g++ -Isrc/demo -Isrc/numbers -Isrc/graphs -g -c -Wall -std=c++20 -c src/numbers/ostream_helper.cpp -o out/numbers/ostream_helper.o
create out/graphs/
g++ -Isrc/demo -Isrc/numbers -Isrc/graphs -g -c -Wall -std=c++20 -c src/graphs/main.cpp -o out/graphs/main.o
g++ -Isrc/demo -Isrc/numbers -Isrc/graphs -g -c -Wall -std=c++20 -c src/graphs/graph.cpp -o out/graphs/graph.o
g++ -Isrc/demo -Isrc/numbers -Isrc/graphs -g -c -Wall -std=c++20 -c src/graphs/shortest_path.cpp -o out/graphs/shortest_path.o
g++ -o main.out out/main.o out/demo/demo.o out/numbers/numbers.o out/numbers/numbers_functions.o out/numbers/ostream_helper.o out/graphs/main.o out/graphs/graph.o out/graphs/shortest_path.o
```

Run the program:

```sh
./main.out graphs g2        # run the program using graph 'g2'
```

New output from `src/graphs/main.cpp` shows:

```
Graphs::main() in graphs/main.cpp:
graph g:
'A' --> ('B':2), ('D':8)
'B' --> ('A':2), ('D':5), ('E':6)
'C' --> ('E':9), ('F':3)
'D' --> ('A':8), ('B':5), ('E':3), ('F':2)
'E' --> ('B':6), ('C':9), ('D':3), ('F':1)
'F' --> ('C':3), ('D':2), ('E':1)

shortest-path('S','E'):
 - ('S':0) --> ('X':20) --> ('E':80)
 - distance: 100
```

The source code producing this output in `src/graphs/main.cpp`:

```c++
/**
 * main() function in Graphs:: namespace that prints command line arguments.
 *
 * @param argc number of command line arguments.
 * @param argv vector with command line arguments.
 * @return 0 for successfull execution or other exit code for failure.
 */
int main(int argc, char *argv[]) {
    cout << "Graphs::main() in graphs/main.cpp:" << endl;

    Graph g2;
    g2.edge('A', 'B', 2).edge('A', 'D', 8)
        .edge('B', 'D', 5).edge('B', 'E', 6)
        .edge('C', 'E', 9).edge('C', 'F', 3)
        .edge('D', 'E', 3).edge('D', 'F', 2)
        .edge('E', 'F', 1);

    // select graph, start and end node
    Graph& g = g2;
    char from='A';
    char to='C';

    // print selected graph
    cout << "graph g:\n" << g << endl;

    // compute and print shortest path
    Path& shortest_path = g.shortest_path(from, to);
    cout << "shortest-path('" << from << "','" << to << "'):\n - "
        << shortest_path
        << "\n - distance: "
        << shortest_path.distance() << "" << endl;

    return EXIT_SUCCESS;
}
```


&nbsp;

## 2. Data Modeling

Graphs are not directly supported in programming languages (there are
[Graph databases](https://en.wikipedia.org/wiki/Graph_database)).

An efficient *data structure* must be chosen to implement a *undirected*
graph with *weighted edges*.

[Adjacency matrix](https://en.wikipedia.org/wiki/Adjacency_matrix) is one
possibility. Adjacency matrix is a symmetric *n x n* matrix with rows and
colums for each node. Each `cell [i,j]` holds the *weight* of the edge
between nodes `i` and `j`.

Answer questions:

1. How can an adjacency matrix be implemented?

1. What are advantages / disadvantages of an adjacency matrix?

1. What is the resource (memory) use of an adjacency matrix of size *n*
    (*n* nodes)?

1. What is the effect of *undirected* edges for an adjacency matrix?
    How much memory is "wasted"?

1. What is the most frequent access pattern of matrix elements?
    Is an adjacency matrix the best approach?

1. What is a [Sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix)?
    What are advantages / disadvantages?


&nbsp;

Header file [src/graphs/graph.h](src/graphs/graph.h) defines a
class `Graph` to store a graph:

```c++
/**
 * Class to represent undirected graph of nodes and weighted edges.
 */
class Graph {
    // graph as map of nodes with edges starting at each node
    map<char, map<char, int>>& edges;

    public:
    Graph() : edges(*new map<char, map<char, int>>()) { };
    ~Graph() { delete &edges; };

    Graph& edge(char n1, char n2, int weight, bool add_mirror=true);
    Path& shortest_path(char start, char end);

    friend ostream& operator<<(std::ostream& out, const Graph& g);
};
```

(7.) Which data structure is used to store a graph?

(8.) Sketch a drawing of how a graph is stored in class `Graph`:

```
('A')--<27>--('B')--<12>--('C')
               |           /
              <7>        <4>
               |         /
             ('D')------+
```

A graph is built using the `edge()` - method of class `Graph`:

```c++
Graph g;
g.edge('A', 'B', 2).edge('A', 'D', 8)
 .edge('B', 'D', 5).edge('B', 'E', 6)
 .edge('C', 'E', 9).edge('C', 'F', 3)
 .edge('D', 'E', 3).edge('D', 'F', 2)
 .edge('E', 'F', 1);
```

(9.) Draw the resulting graph.

(10.) How is it possible that invocations of method `edge()` can concatenated
    (*"chained"*)?

(11.) What is [Method chaining](https://en.wikipedia.org/wiki/Method_chaining)?
    Which property must *"chainable"* methods have?

(12.) How can a *"Path"* between two nodes be represented as data structure?


&nbsp;

## 3. Shortest-Path Algorithm

<!--
[video (FelixTechTips)](https://youtu.be/bZkzH5x0SKU?si=n8Z2ZIfbB73_v1TE)
<img src="../markup/img/graph_2a.jpg" alt="drawing" width="640"/>
-->
Watch the
[Video (Mike Pound, Computerphile channel)](https://youtu.be/GazC3A4OQTE?si=ZuBEcWaBzuKmPMqA)
(10:42 min) and understand how
[Dijkstra's Shortest Path Algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
(1956) works.

<img src="https://raw.githubusercontent.com/sgra64/mdse/markup/g1-graphs/Mike_Pound_Dijkstras_algorithm.jpg" alt="drawing" width="400"/>

Seeking the shortest path between nodes `'S'` and `'E'`:

<img src="https://raw.githubusercontent.com/sgra64/mdse/markup/g1-graphs/graph_1.jpg" alt="drawing" width="400"/>

Understand the algorithm.

Identify information it needs.

Implement the algorithm in function *shortest_path()* in `src/graphs/shortest_path.cpp`:

```c++
/**
 * Compute shortest path from start to end node in an undirected,
 * weighter graph using Dijkstra's algorithm.
 * @param start node where path starts
 * @param end node where shortest path ends
 * @return shortest path between start and end node
 */
Path& Graph::shortest_path(char start, char end) {
    Path& path = *new Path();

    /**
     * @TODO: compute shortest path in graph from start to end node
     */
    path.add(start, 0)      // build dummy path
        .add('X', 20)
        .add(end, 80);
    //
    return path;
}
```

The program renders graph `g1` from the video with:

```sh
./main.out graphs graph=g1 start=S end=E
```

Output:

```
graph g1:
'A' --> ('B':3), ('D':4), ('S':7)
'B' --> ('A':3), ('D':4), ('H':1), ('S':2)
'C' --> ('L':2), ('S':3)
'D' --> ('A':4), ('B':4), ('F':5)
'E' --> ('G':2), ('K':5)                <-- end node 'E'
'F' --> ('D':5), ('H':3)
'G' --> ('E':2), ('H':2)
'H' --> ('B':1), ('F':3), ('G':2)
'I' --> ('J':6), ('K':4), ('L':4)
'J' --> ('I':6), ('K':4), ('L':4)
'K' --> ('E':5), ('I':4), ('J':4)
'L' --> ('C':2), ('I':4), ('J':4)
'S' --> ('A':7), ('B':2), ('C':3)       <-- start node 'S'
```

Before the solution is implemented, the program outputs the dummy path:

```
shortest-path('S','E'):
 - ('S':0) --> ('X':20) --> ('E':100)
 - distance: 100
```

With the correct implementation of the `shortest-path` algorithm, the
program outputs the shortest path between nodes `'S'` (start) and
`'E'` (end):

```
shortest-path('S','E'):
 - ('S':0) --> ('B':2) --> ('H':3) --> ('G':5) --> ('E':7)
 - distance: 7
```

Experiment with other paths, e.g. from `'S'` to `'K'` or `'S'` to `'I'`:

```sh
./main.out graphs graph=g1 start=S end=K
./main.out graphs graph=g1 start=S end=I
```
```
shortest-path('S','K'):
 - ('S':0) --> ('B':2) --> ('H':3) --> ('G':5) --> ('E':7) --> ('K':12)
 - distance: 12
 
 shortest-path('S','I'):
 - ('S':0) --> ('C':3) --> ('L':5) --> ('I':9)
 - distance: 9
```

The route via node `'B'` is taken from `'S'` to `'K'` while the upper route
via node `'C'` is taken from `'S'` to `'I'`.


&nbsp;

Example 2:

Using graph `g2` from
[video](https://www.youtube.com/watch?v=bZkzH5x0SKU&ab_channel=FelixTechTips)
(*"FelixTechTips: Dijkstras Shortest Path Algorithm Explained"*)
seeking the shortest path between nodes `'A'` and `'C'`:

<img src="https://raw.githubusercontent.com/sgra64/mdse/markup/g1-graphs/graph_g2a.jpg" alt="drawing" width="400"/>

yields the following output showing the correct shortest path:

```sh
./main.out      # uses defaults: graph=g2 start=A end=C
./main.out graphs graph=g2 start=A end=C
```

```
graph g2:
'A' --> ('B':2), ('D':8)
'B' --> ('A':2), ('D':5), ('E':6)
'C' --> ('E':9), ('F':3)
'D' --> ('A':8), ('B':5), ('E':3), ('F':2)
'E' --> ('B':6), ('C':9), ('D':3), ('F':1)
'F' --> ('C':3), ('D':2), ('E':1)

shortest-path('A','C'):
 - ('A':0) --> ('B':2) --> ('D':7) --> ('F':9) --> ('C':12)
 - distance: 12
```

<img src="https://raw.githubusercontent.com/sgra64/mdse/markup/g1-graphs/graph_g2b.jpg" alt="drawing" width="400"/>
