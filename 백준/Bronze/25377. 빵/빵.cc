#include <iostream>
using namespace std;

int main () {
    int N, minT = 1001;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        if (A <= B && B < minT) minT = B;
    }
    if (minT == 1001) cout << "-1\n";
    else cout << minT << "\n";
    return 0;
}