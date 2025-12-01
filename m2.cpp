#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void reverseArray(ifstream& f);

int main() {
    ifstream f("input.txt");
    if (!f.is_open()) {
        cerr << "Cannot open an input file." << endl;
        return -1;
    }
    
    reverseArray(f);
    
    f.close();
    
    return 0;
}

void reverseArray(ifstream& f) {
    vector<double> numbers;
    double number;
    
    // Читаем все числа в вектор
    while (f >> number) {
        numbers.push_back(number);
    }
    
    // Выводим элементы в обратном порядке
    for (int i = numbers.size() - 1; i >= 0; i--) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}