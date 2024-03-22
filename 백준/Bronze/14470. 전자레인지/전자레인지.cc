#include <iostream>
using namespace std;

int main () {
    int A, B, C, D, E, sum = 0;
    cin >> A >> B >> C >> D >> E;
    if (A < 0) {
        sum += A * -1 * C;
        sum += D;
        sum += B * E;
    } else {
        sum += (B - A) * E;
    }
    cout << sum << "\n";
    return 0;
}