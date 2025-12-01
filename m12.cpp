#include <iostream>
#include <fstream>

using namespace std;

void sortArray(ifstream& f);

int main() {
    ifstream f("input.txt");
    if (!f.is_open()) {
        cerr << "Cannot open an input file." << endl;
        return -1;
    }
    
    sortArray(f);
    
    f.close();
    
    return 0;
}

void sortArray(ifstream& f) {
    const int MAX_SIZE = 1000;
    double numbers[MAX_SIZE];
    int count = 0;
    double number;
    
    while (f >> number && count < MAX_SIZE) {
        numbers[count] = number;
        count++;
    }
    
    // Сортировка пузырьком
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    
    // Выводим отсортированный массив
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}