#include "AbstractBaseClassGraph.hpp"
#include <iostream>
#include <vector>
#pragma once

class AdjacencyListGraph : public GraphBase{
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;

    public:

    AdjacencyListGraph() {
        numVertices = 0;
        adjacencyList.resize(0);
    }

    AdjacencyListGraph(int num) : numVertices(num){
        adjacencyList.resize(numVertices);
    };

    void addEdge(int v1, int v2){
        if ((v1 >= 0 && v1 < numVertices) && (v2 >= 0 && v2 < numVertices)){
            adjacencyList[v1].push_back(v2);
            adjacencyList[v2].push_back(v1);
        }
    }

    void removeEdge(int v1, int v2){
        if ((v1 >= 0 && v1 < numVertices) && (v2 >= 0 && v2 < numVertices)){
            for (auto it = adjacencyList[v1].begin(); it != adjacencyList[v1].end(); ++it){
                if (*it == v2){
                    adjacencyList[v1].erase(it);
                    break;
                }
            }

            for (auto it = adjacencyList[v2].begin(); it != adjacencyList[v2].end(); ++it){
                if (*it == v1){
                    adjacencyList[v2].erase(it);
                    break;
                }
            }
        }
    }

    bool isEdge(int v1, int v2){
        if ((v1 >= 0 && v1 < numVertices) && (v2 >= 0 && v2 < numVertices)){
            for (int vertex : adjacencyList[v1]){
                if (vertex == v2){
                    return true;
                }
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < numVertices; i++){
            std::cout << i << " -> ";
            for (int vertex : adjacencyList[i]){
                std::cout << vertex << ", ";
            }
            std::cout << std::endl;
        }
    }

    int getNumVertices(){
        return numVertices;
    }

    int getNumEdges(){
        int num = 0;
        for (int i = 0; i < numVertices; i++){
            num += adjacencyList[i].size();
        }
        // We divide by 2 because the edges are counted twice
        return num / 2;
    }

    void Resize(int num){
        adjacencyList.resize(num);
    }

    std::vector<std::vector<int>>& getVec(){
        return adjacencyList;
    }
};