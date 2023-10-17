#include "AbstractBaseClassGraph.hpp"
#include <iostream>
#include <vector>
#pragma once

class AdjacencyMatrixGraph : public GraphBase {
private:
    int numVertices;
    std::vector<std::vector<bool>> adjacencyMatrix;

public:
    AdjacencyMatrixGraph(int n) : numVertices(n) {
        adjacencyMatrix.assign(numVertices, std::vector<bool>(numVertices, false));
    }

    void addEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
            adjacencyMatrix[v1][v2] = true;
            adjacencyMatrix[v2][v1] = true;
        }
    }

    void removeEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
            adjacencyMatrix[v1][v2] = false;
            adjacencyMatrix[v2][v1] = false;
        }
    }

    bool isEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
            return adjacencyMatrix[v1][v2];
        }
        return false;
    }

    void display() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    int getNumVertices() {
        return numVertices;
    }

    int getNumEdges() {
        int numEdges = 0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = i + 1; j < numVertices; j++) {
                if (adjacencyMatrix[i][j])
                    numEdges++;
            }
        }
        return numEdges;
    }
};

