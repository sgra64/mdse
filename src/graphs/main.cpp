#include "graph.h"
#include <string.h>

namespace Graphs {

    string val(string key, string str);     // forward declaration

    /**
     * main() function in Graphs:: namespace that prints command line arguments.
     * Invoke program with parameters:
     *   ./main.out
     *   ./main.out graphs graph=g2 start=A end=C
     *   ./main.out graphs graph=g1 start=S end=E
     *
     * @param argc number of command line arguments.
     * @param argv vector with command line arguments.
     * @return 0 for successfull execution or other exit code for failure.
     */
    int main(int argc, char *argv[]) {
        cout << "Graphs::main() in graphs/main.cpp:" << endl;

        string graph="g2";      // default graph
        char start='A';         // default start node
        char end='C';           // default end node
        //
        for(int i=1; i < argc; i++) {
            string arg;
            if((arg=val("start=", argv[i])).length() > 0) { start=arg[0]; }
            if((arg=val("end=",   argv[i])).length() > 0) { end=arg[0];   }
            if((arg=val("graph=", argv[i])).length() > 0) { graph=arg;    }
        }

        // graph g1 from Computerphile video of Dijkstra's Algorithm,
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

        // smaller graph g2 from FelixTechTips
        // https://www.youtube.com/watch?v=bZkzH5x0SKU
        Graph g2;
        g2.edge('A', 'B', 2).edge('A', 'D', 8)
          .edge('B', 'D', 5).edge('B', 'E', 6)
          .edge('C', 'E', 9).edge('C', 'F', 3)
          .edge('D', 'E', 3).edge('D', 'F', 2)
          .edge('E', 'F', 1);

        // select graph to use
        Graph &g = graph=="g1"? g1 : graph=="g2"? g2 : g2;

        // print selected graph
        cout << "graph " << graph << ":\n" << g << endl;

        // compute and print shortest path
        Path& shortest_path = g.shortest_path(start, end);
        cout << "shortest-path('" << start << "','" << end << "'):\n - "
            << shortest_path
            << "\n - distance: "
            << shortest_path.distance() << "" << endl;

        return EXIT_SUCCESS;
    }

    /**
     * Parse value from "key=value" string (e.g. used in argv[]).
     * @param key key including "="
     * @param str string to parse
     * @return value as string or "" if key did not match str
     */
    string val(string key, string str) {
        unsigned int l1 = key.length();
        if(str.length() > l1 && str.rfind(key, 0)==0) {
            return str.substr(l1, str.length() - l1);
        }
        return "";
    }
}