#ifndef GRAPHS_H
#define GRAPHS_H
#include<map>
#include<vector>
#include<iostream>
using namespace std;

namespace Graphs {

    class Path;     // forward declaration of class Path

    /**
     * Class to represent undirected graph of nodes and weighted edges.
     */
    class Graph {
        // private attribute to store graph as map of nodes with edges
        // starting at each node
        map<char, map<char, int>>& edges;

      public:
        Graph() : edges(*new map<char, map<char, int>>()) { };
        ~Graph() { delete &edges; };

        Graph& edge(char n1, char n2, int weight, bool add_mirror=true);
        Path& shortest_path(char start, char end);

        friend ostream& operator<<(std::ostream& out, const Graph& g);
    };

    /**
     * Class to represent path of nodes and weighted edges.
     */
    class Path {
        // private attribute: path as vector of edges with weights
        vector<pair<char, int>>& path;

        // private attribute: distance of path
        int dist;

      public:
        Path() : path(*new vector<pair<char, int>>), dist(0) { };
        ~Path() { delete &path; };

        Path& add(char n, int distance);
        int length();
        int distance() { return dist; };

        friend ostream& operator<<(std::ostream& out, const Path& p);
    };

    /**
     * ostream operator << to print graph.
     * @param out ostream on left-side of << operator
     * @param g graph to print
     * @return chainable self-reference
     */
    ostream& operator<<(std::ostream& out, const Graph& g);

    /**
     * ostream operator << to print path in graph.
     * @param out ostream on left-side of << operator
     * @param path path to print
     * @return chainable self-reference
     */
    ostream& operator<<(std::ostream& out, const Path& p);

    /**
     * main() function in Numbers namespace.
     * @param argc number of command line arguments in argv
     * @param argv command line arguments
     * @return process exit code
     */
    int main(int argc, char *argv[]);

}
#endif // GRAPHS_H