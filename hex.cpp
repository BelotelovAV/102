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
        