#include "graph.h"

namespace Graphs {

    /**
     * main() function in Demo:: namespace that prints command line arguments.
     *
     * @param argc number of command line arguments.
     * @param argv vector with command line arguments.
     * @return 0 for successfull execution or other exit code for failure.
     */
    int main(int argc, char *argv[]) {
        cout << "Graphs::main() in graphs/main.cpp:" << endl;

        // graph from Computerphile video of Dijkstra's Algorithm,
        // https://www.youtube.com/watch?v=GazC3A4OQTE
        Graph g1;
        g1.edge('S', 'A', 7).edge('S', 'B', 2).edge('S', 'C', 3)
          .edge('A', 'B', 3).edge('A', 'D', 4)
          .edge('B', 'H', 1).edge('B', 'D', 4)
          .edge('C', 'L', 2)
          .edge('D', 'F', 5)
          .edge('E', 'G', 2).edge('E', 'K', 5)
          .edge('F', 'H', 3)
          .edge('G', 'H', 2)
          .edge('I', 'J', 6).edge('I', 'K', 4).edge('I', 'L', 4)
          .edge('J', 'K', 4).edge('J', 'L', 4);

        Graph g2;
        g2.edge('A', 'B', 2).edge('A', 'D', 8)
          .edge('B', 'D', 5).edge('B', 'E', 6)
          .edge('C', 'E', 9).edge('C', 'F', 3)
          .edge('D', 'E', 3).edge('D', 'F', 2)
          .edge('E', 'F', 1);

        // select graph, start and end node
        Graph& g = g1;
        char from='S';
        char to='E';

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
}