#include <iostream>
using namespace std;

int main () {
    int A, B, C, a, b, c, sum = 0;
    cin >> A >> B >> C >> a >> b >> c;
    if (A < a) sum += (a - A);
    if (B < b) sum += (b - B);
    if (C < c) sum += (c - C);
    cout << sum << "\n";
    return 0;
}