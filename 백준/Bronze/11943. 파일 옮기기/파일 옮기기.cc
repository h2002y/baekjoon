#include <iostream>
using namespace std;

int main () {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A + D < B + C) cout << A + D << "\n";
    else cout << B + C << "\n";
    return 0;
}