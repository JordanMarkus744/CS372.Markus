// I will create a social graph for a group of 20 people including me and Kevin Bacon, then build a function that will take that graph as a reference and see if i have a connection
// to Kevin Bacon, and if so, print out the connection
#include "SocialGraph.hpp"
#include <iostream>

int main(){
    SocialGraph social(20);
    social.addEdge(0, 1, "Jordan", "Baxter");
    social.addEdge(0,2,"Jordan", "Thomas");
    social.addEdge(1, 3, "Baxter", "Kyle");
    social.addEdge(2, 4, "Thomas" , "Markus");
    social.addEdge(4, 5, "Markus", "Andy");
    social.addEdge(4, 1, "Andy", "Baxter");
    social.addEdge(2, 5, "Thomas", "Kevin Bacon");
    social.addEdge(0, 6, "Jordan", "Jayson");
    social.addEdge(6, 7, "Jayson", "Tyler");
    social.addEdge(0, 7, "Jordan", "Tyler");
    social.addEdge(0, 8, "Jordan", "Jackson");
    social.addEdge(0, 9, "Jordan", "Andrew");
    social.addEdge(0, 10, "Jordan", "Kobe");
    social.addEdge(0, 11, "Jordan", "Regan");
    social.addEdge(0, 12, "Jordan", "Reese");
    social.addEdge(0, 13, "Jordan", "Ramsey");
    social.addEdge(0, 14, "Jordan", "Ella");
    social.addEdge(0, 15, "Jordan", "Paris");
    social.addEdge(0, 16, "Jordan", "Mercedes");
    social.addEdge(0, 17, "Jordan", "Jon");
    social.addEdge(0, 18, "Jordan", "Dillon");
    social.addEdge(0, 19, "Jordan", "Layton");
    social.display();


    int me = 0;
    int kevinBacon = 5;

    std::vector<int> path;
    bool isConnected = social.isConnected(me, kevinBacon, path);

    if (isConnected) {
        std::cout << "You are connected to Kevin Bacon! Path: ";
        for (int person : path) {
            std::cout << person << " -> ";
        }
        std::cout << kevinBacon << std::endl;
    } else {
        std::cout << "You are not connected to Kevin Bacon." << std::endl;
    }


    return 0;
}