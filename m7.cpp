#include <iostream>
#include <fstream>

using namespace std;

void removeNegatives(ifstream& f);

int main() {
    ifstream f("input.txt");
    if (!f.is_open()) {
        cerr << "Cannot open an input file." << endl;
        return -1;
    }
    
    removeNegatives(f);
    
    f.close();
    
    return 0;
}

void removeNegatives(ifstream& f) {
    const int MAX_SIZE = 1000;
    int numbers[MAX_SIZE];
    int count = 0;
    int number;
    
    while (f >> number && count < MAX_SIZE) {
        numbers[count] = number;
        count++;
    }
    
    int j = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] >= 0) {
            swap(numbers[i], numbers[j]);
            j++;
        }
    }
    
    for (int i = j; i < count; i++) {
        numbers[i] = 0;
    }
    
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}