#include <iostream>
#include "graph.hpp"

int main() {
    
    Graph g(5);

   
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout << "Graph Representation:\n";
    g.displayGraph();
    g.dfs(0);
    g.bfs(0);

    return 0;
}

