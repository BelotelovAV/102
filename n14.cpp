#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int countMinElements(ifstream& f);

int main() {
    ifstream f("input.txt");
    if (!f.is_open()) {
        cerr << "Cannot open an input file." << endl;
        return -1;
    }
    
    int result = countMinElements(f);
    
    f.close();

    cout << result << endl;
    
    return 0;
}

int countMinElements(ifstream& f) {
    int minValue = INT_MAX;
    int count = 0;
    int number;
    
    while (f >> number) {
        if (number < minValue) {
            minValue = number;
            count = 1;
        } else if (number == minValue) {
            ++count;
        }
    }
    
    return count;
}
