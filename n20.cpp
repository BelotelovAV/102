#include <iostream>
#include <fstream>

using namespace std;

double averageUniqueSegments(ifstream& f);

int main() {
    ifstream f("input.txt");
    if (!f.is_open()) {
        cerr << "Cannot open an input file." << endl;
        return -1;
    }
    
    double result = averageUniqueSegments(f);
    
    f.close();

    cout << result << endl;
    
    return 0;
}

double averageUniqueSegments(ifstream& f) {
    int current, previous;
    int sum = 0;
    int count = 0;
    
    if (!(f >> previous)) {
        return 0.0; // Пустой файл
    }
    
    sum = previous;
    count = 1;
    
    while (f >> current) {
        if (current != previous) {
            sum += current;
            count++;
            previous = current;
        }
    }
    
    return static_cast<double>(sum) / count;
}