#include <iostream>
using namespace std;

int main () {
    int A, B, C;
    cin >> A >> B >> C;
    if (A + B >= C * 2) cout << A + B - (C * 2) << "\n";
    else cout << A + B << "\n";
    return 0;
}