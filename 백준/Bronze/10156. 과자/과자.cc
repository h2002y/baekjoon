#include <iostream>
using namespace std;

int main () {
    int K, N, M;
    cin >> K >> N >> M;
    int total = K * N - M;
    if (total > 0) cout << total << "\n";
    else cout << "0\n";
    return 0;
}