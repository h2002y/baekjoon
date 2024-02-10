#include <iostream>
using namespace std;

int main () {
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    int maxDay = 0;
    for (int i = 1; i <= L; ++i) {
        if (C * i >= A && D * i >= B) {
            maxDay = L - i;
            break;
        }
    }
    cout << maxDay << "\n";
    return 0;
}