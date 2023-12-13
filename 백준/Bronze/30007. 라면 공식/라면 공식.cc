#include <iostream>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++) {
        int A, B, X;
        cin >> A >> B >> X;
        int W = A * (X - 1) + B;
        cout << W << "\n";
    }
    return 0;
}