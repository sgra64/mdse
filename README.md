<!-- check-out single branch from repo:
        git clone -b G1 --single-branch https://github.com/sgra64/mdse.git
 -->

# Assignment G1: Graphs (shortest path)

A *[Graph](https://en.wikipedia.org/wiki/Graph_theory)*
is a set of *nodes* (vertices) and *edges* connecting nodes G = { n ∈ N, e ∈ E }.
A *weighted Graph* has *weights* associated with egdes.

The task is to find the *"shortest path"* between a *start node* `S` and
an *end node* `E`. The attribute *"shortest"* refers to the minimum added weight
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


| aaa | bbb |
| aaa | bbb |
| aaa | bbb |

<table>
<td>
<img src="https://upload.wikimedia.org/wikipedia/commons/d/d9/Edsger_Wybe_Dijkstra.jpg" alt="drawing" width="400"/>
</td>
<td>
*Edsger W. Dijkstra* (1930-2003,
[bio](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra))
was a Dutch computer scientist, software engineer, professor of Computer Science
at the Univerity of Austin, Texas who developed
[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
to find a shortest
path in an undirected, weighted graph. He received the
[Turing Award](https://en.wikipedia.org/wiki/Turing_Award)
for this and numerous other contributions in computer science in 1972.
</td>
</table>


The algorithm was used in a Bachelor thesis by
[Steffen Ansorge](https://www.linkedin.com/in/steffenansorge):
*"Planning and development of a system for route planning with unreliable position
data of intermediate stops"*,
[.pdf](https://drive.google.com/file/d/1vceT1_HE0IxMuiheIbkkzwUEKi106gMX).


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

# add link of remote repository under name 'mdse-repo'
git remote add mdse-repo https://github.com/sgra64/mdse.git

# fetch branch G1-graphs from the remote repository
git fetch mdse-repo G1-graphs:G1-graphs

# merge content of fetched branch into current branch (branch: main)
git merge --allow-unrelated-histories --strategy-option theirs G1-graphs
```

Inspecting content of files,

```sh
find src                    # show source files in dev-container after merge
```

new files under `src/graphs` appear:

```
src
src/graphs
src/graphs/shortest_path.cpp
src/graphs/main.cpp
src/graphs/graph.cpp
src/graphs/graph.h
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

`makefile` was modified in the merge to include new dependencies for `graphs`-files.
Compare differences that were made in `makefile`:

```sh
git diff HEAD~1 HEAD makefile
```
```
```

Show which files were modified in the merge (M: modified, A: added, D: deleted):

```sh
git diff HEAD~1 --name-status   # show differences made by the merge
```
```
```

The merge can be reset and the previous state of the project restore:

```sh
git reset --hard            # reset project to pre-merge state

find src                    # files under: src/graphs are gone
```
```
```

Of course, the merge can be repeated

```sh
git merge --allow-unrelated-histories --strategy-option theirs G1-graphs
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
class Graph {
    // graph as map of nodes with edges starting at each node
    map<char, map<char, int>>& edges;

  public:
    Graph() : edges(*new map<char, map<char, int>>()) { };
    ~Graph() { delete &edges; };

    Graph& edge(char n1, char n2, int weight, bool add_mirror=true);
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
and understand how
[Dijkstra's Shortest Path Algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
(1956) works.

<img src="https://raw.githubusercontent.com/sgra64/mdse/markup/g1-graphs/Mike_Pound_Dijkstras_algorithm.jpg" alt="drawing" width="400"/>


Implement the algorithm in

