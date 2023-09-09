#include <iostream>
#include "HotPotato.hpp"

int main(){ // I used a doubly Circular Linked List for the base of this game
    HotPotato game;
    game.PlayGame(5,0); // First integer input is the amount of players, second integer input is how many tosses until someone is out
    return 0;
}