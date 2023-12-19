#include <iostream>
using namespace std;

int main() {
    int N, even = 0, odd = 0;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if(num % 2 == 0) ++even;
        else ++odd;
    }
    if(even > odd) cout << "Happy\n";
    else cout << "Sad\n";
    return 0;
}