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
}
#else
#include SOLUTION_FILE
#endif