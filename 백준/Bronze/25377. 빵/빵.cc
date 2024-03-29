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
    cout << minT << "\n";
    return 0;
}