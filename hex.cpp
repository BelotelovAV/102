#include <iostream>
#include <cassert>

using namespace std;

constexpr const char * DIGITS = "0123456789ABCDEF";
constexpr int NUM_DIGITS = 16;
int d = 16;

void int2txt(int n, int d, char *txt, int maxLen);

int main(){
    char txt[256];
    while(true){
        int n;
        cout << "Enter n: ";
        cin >> n;
        if (!cin|n<0)
            break;
        int2txt(int n, int d, txt, 256);
        cout << "n= " << txt << endl;
    }
    return 0;
}

void int2txt(int n, int d, char *txt, int maxLen){
    if (n == 0) {
        txt[0] = '0';
        txt[1] = 0;
        return;
    }
    assert(n > 0);
    int k = 0;
    while (n>0 && k < maxLen-1){
        int c = n%d;
        txt[k] = DIGITS[c];
        ++k;
    }
    txt[k] = 0;
    
    //invert the text
    
    for (int i = 0, j = k-1; i<j; ++i, --j){
        char tmp = txt[i];
        txt[i] = txt[j];
        txt[j] = tmp;
    }
}