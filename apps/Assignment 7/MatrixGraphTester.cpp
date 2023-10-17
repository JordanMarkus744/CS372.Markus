#include <iostream>
#include "AdjacencyMatrixClass.hpp"

int main(){
    AdjacencyMatrixGraph matrixGraph(4);
    matrixGraph.addEdge(0, 1);
    matrixGraph.addEdge(0, 2);
    matrixGraph.addEdge(1, 2);
    matrixGraph.addEdge(2, 3);

    std::cout << "\nAdjacency Matrix Graph:" << std::endl;
    matrixGraph.display();
}