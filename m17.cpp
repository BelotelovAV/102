#include <iostream>
#include <fstream>

using namespace std;

void binom(int n, int *c);

int main() {
    int n;
    cout << "Binom Coef: " << endl;
    cin >> n;
    if (n < 0){
        cerr << "Incorrect n" << endl;
        return (-1);
    }
    int c = new int[n+1];
    
    binom (n, c);
    
    for (int k = 0, k <= n; ++k){
        if (k>0)
            cout << ' ';
        cout << c[k];
    }
    cout << endl;
    
    delete[] c;
    return 0;
    
}

void binom(int n, int *c){
    c[0] = 1;
    int m = 0;
    for (m = 1; m <= n; ++m){
        c[m] = 1;
        for (int k = m-1; k > 0; --k){
            c[k] += c[k-1];
        }
    }
}
            