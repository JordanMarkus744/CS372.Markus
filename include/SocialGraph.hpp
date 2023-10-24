#include "AdjacencyListGraphClass.hpp"
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#pragma once

class SocialGraph : public AdjacencyListGraph {
    private:
    int numElements;
    
    AdjacencyListGraph numVector; // This is for checking connections and will be parallel with the string vector which will hold the names of the people in my social graph
    std::vector<std::vector<std::string>> stringVector;
    std::vector<std::vector<int>> adjacentVector;

    public:


    SocialGraph(int num) : numElements(num){
        numVector.Resize(num);
        stringVector.resize(num);
        adjacentVector = numVector.getVec();
    }

    void addEdge(int v1, int v2, std::string s1, std::string s2){
        numVector.addEdge(v1, v2);
        if ((v1 >= 0 && v1 < numElements) && (v2 >= 0 && v2 < numElements)){
            stringVector[v1].push_back(s2);
            stringVector[v2].push_back(s1);
        }
    }

    void removeEdge(int v1, int v2){
        if ((v1 >= 0 && v1 < numElements) && (v2 >= 0 && v2 < numElements)){
            //adjacentVector = numVector.getVec(); may not need this since i said that adjacent vector is a reference to the numVector vector in the constructor
            auto strIt = stringVector[v1].begin();

            for (auto it = adjacentVector[v1].begin(); it < adjacentVector[v1].end(); ++it){
                ++strIt;
                if (*it == v2){
                    adjacentVector[v1].erase(it);
                    stringVector[v1].erase(strIt);
                    break;
                }
            }

            strIt = stringVector[v2].begin();
            for (auto it = adjacentVector[v2].begin(); it < adjacentVector[v2].end(); ++it){
                ++strIt;
                if (*it == v1){
                    adjacentVector[v2].erase(it);
                    stringVector[v2].erase(strIt);
                }
            }
        }
    }

    bool isConnected(int person1, int person2, std::vector<int>& path) {
    std::vector<bool> visited(numElements, false);
    std::vector<int> parent(numElements, -1);

    std::queue<int> queue;
    visited[person1] = true;
    queue.push(person1);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        for (int neighbor : adjacentVector[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                queue.push(neighbor);

                if (neighbor == person2) {
                    // Found a path
                    int node = person2;
                    while (node != -1) {
                        path.push_back(node);
                        node = parent[node];
                    }
                    reverse(path.begin(), path.end());
                    return true;
                }
            }
        }
    }

    return false; // No path found
}

    bool isEdge(int v1, int v2){
        if ((v1 >= 0 && v1 < numElements) && (v2 >= 0 && v2 < numElements)){
            for (int vert : adjacentVector[v1]){
                if (vert == v2){
                    return true;
                }
            }
        }
        return false;
    }

    void display(){
        numVector.display();
        std::vector<std::string> temp = {"Jordan", "Baxter", "Thomas", "Kyle", "Markus", "Andy", "Kevin Bacon", "Jayson", "Tyler", "Jackson", "Andrew", "Kobe", "Regan", "Reese", "Ramsey", "Ella", "Paris", "Mercedes", "Jon", "Dillon", "Layton"};
        for (int i = 0; i < numElements; i++){
            std::cout << temp[i] << " -> ";
            for (std::string vert : stringVector[i]){
                std::cout << vert << ", ";
            }
            std::cout << "\n\n";
        }
    }

    int getNumVertices(){
        return numElements;
    }

    int getNumEdges(){
        int num = 0;
        for (int i = 0; i < numElements; i++){
            num += adjacentVector[i].size();
        }
        // We divide by 2 because the edges are counted twice
        return num / 2;
    }
};