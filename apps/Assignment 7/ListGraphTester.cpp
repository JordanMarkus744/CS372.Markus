#include <iostream>
#include "AdjacencyListGraphClass.hpp"

int main() {
    AdjacencyListGraph listGraph(4);
    listGraph.addEdge(0, 1);
    listGraph.addEdge(0, 2);
    listGraph.addEdge(1, 2);
    listGraph.addEdge(2, 3);

    std::cout << "Adjacency List Graph:" << std::endl;
    listGraph.display();

    

    return 0;
}