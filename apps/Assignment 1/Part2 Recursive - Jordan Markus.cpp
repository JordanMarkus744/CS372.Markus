#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int , int , int );

int main() {
    chrono::time_point<chrono::system_clock> start, end;
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 7;
    
    for (auto numdisks: {5,10,15, 20, 25,30,35}) {
        start = chrono::system_clock::now();
        cout << "Numdisks: " << numdisks << endl;
        moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
        cout << "Moved " << numdisks << " pegs"
           << " from peg " << FROMPEG
           << " to peg " << TOPEG << endl;
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        cout << "\nTook " << elapsed_seconds.count() << "s\n";
        string stop;
        cin >> stop;
    }
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
     if (num > 0) {
        moveDisks(num -1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num-1, tempPeg, toPeg, fromPeg);
     }
}

void printIt(int disk, int fromPeg, int toPeg) {
  // Do nothing for timing test, but otherwise
  cout<< "Move disk " << disk
      << " from pef " << fromPeg
      << " to peg " << toPeg << endl;
}