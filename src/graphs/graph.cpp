#include "graph.h"

namespace Graphs {

    /**
     * Add weighted edge to graph. An edge defines a link between two nodes
     * with a weight. Edge is added in both directions 'A'-'B' and 'B'-'A'
     * by default (add_mirror=true).
     * @param n1 edge, left-side
     * @param n2 edge, right-side
     * @param weight edge weight
     * @param add_mirror add also reverse edge, if true (default)
     * @return chainable self-reference
     */
    Graph& Graph::edge(char n1, char n2, int weight, bool add_mirror) {
        if(edges.find(n1) == edges.end()) {
            edges[n1] = *new map<char, int>();  // key is not yet present
        }
        edges[n1][n2] = weight;
        if(add_mirror) {
            edge(n2, n1, weight, false);
        }
        return *this;
    }

    /**
     * Add node with edge weight to path.
     * @param n node added to path
     * @param weight weight associated with node edge
     * @return chainable self-reference
     */
    Path& Path::add(char n, int weight) {
        auto p = *new pair<char, int>(n, weight);
        path.push_back(p);
        return *this;
    }

    /**
     * Return number of edges in path.
     * @return number of edges (length)
     */
    int Path::length() {
        return path.size();
    }

    /**
     * Return sum of weights of all path edges.
     * @return sum of weights (distance)
     */
    int Path::distance() {
        int dist=0;
        for(auto const& e : path) {
            dist += e.second;   // sum edge weight
        }
        return dist;
    }

    /**
     * ostream operator << to print graph.
     * @param out ostream on left-side of << operator
     * @param g graph to print
     * @return chainable self-reference
     */
    ostream& operator<<(ostream& out, const Graph& g) {
        for(auto const& node_edges : g.edges) {
            char from = node_edges.first;
            cout << "'" << from << "' --> ";
            string m1 = "";
            for(auto const& edge : node_edges.second) {
                char to = edge.first;
                int weight = edge.second;
                cout << m1 << "('" << to << "':" << weight << ")";
                m1 = ", ";
            }
            cout << "" << endl;
        }
        return cout;
    }

    /**
     * ostream operator << to print path in graph.
     * @param out ostream on left-side of << operator
     * @param path path to print
     * @return chainable self-reference
     */
    ostream& operator<<(ostream& out, const Path& p) {
        string m1 = "";
        for(auto const& p : p.path) {
            cout << m1 << "('" << p.first << "':" << p.second << ")";
            m1 = " --> ";
        }
        return cout;
    }
}