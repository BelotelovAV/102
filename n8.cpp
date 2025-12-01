#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int upDown(istream& f);

int main() {
    ifstream f("input.txt");
    if (!f.is_open()) {
        cerr << "Cannot open an input file." << endl;
        return -1;
    }
    
    int n = upDown(f);    
    f.close();
    
    cout << "Result: " << n << endl;
    ofstream g("output.txt");
    g << n << endl;
    g.close();
    return 0;
}

int upDown(istream& f) {
    int previous = 0;
    int sequenceType = 0; // -1 descending, 0 not determined/equal, 1 ascending
    bool firstElement = true;
    int x;
    
    while (f >> x) {
        if (firstElement) {
            previous = x;
            firstElement = false;
            continue;
        }
        
        if (sequenceType == 0) {
            if (x > previous) {
                sequenceType = 1;
            } else if (x < previous) {
                sequenceType = -1;
            }
        } 
        else if (sequenceType == 1) {
            if (x < previous) {
                return 0;
            }
        } 
        else if (sequenceType == -1) {
            if (x > previous) {
                return 0;
            }
        }
        
        previous = x;
    }
    
    if (sequenceType == 1) {
        return 1;
    } else if (sequenceType == -1) {
        return -1;
    } else {
        return 1;
    }
}           
