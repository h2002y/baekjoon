#include <iostream>
using namespace std;

int main () {
    int A, B, C;
    cin >> A >> B >> C;
    if (A != B && B == C) cout << "A\n";
    else if (B != A && A == C) cout << "B\n";
    else if (C != A && A == B) cout << "C\n";
    else cout << "*\n";
    return 0;
}