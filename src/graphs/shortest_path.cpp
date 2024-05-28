#include "graph.h"
//
#define SOLUTION_FILE "shortest_path_sol.cpp"
#if ! __has_include(SOLUTION_FILE)

namespace Graphs {

    /**
     * Compute shortest path from start to end node in an undirected,
     * weighter graph using Dijkstra's algorithm.
     * @param start node where path starts
     * @param end node where shortest path ends
     * @return shortest path between start and end node
     */
    Path& shortest_path(Graph& g, char start, char end) {
        Path& path = *new Path();
        path.add(start, 10)
            .add('B', 4)
            .add(end, 9);
        //
        return path;
    }
}
#else
#include SOLUTION_FILE
#endif