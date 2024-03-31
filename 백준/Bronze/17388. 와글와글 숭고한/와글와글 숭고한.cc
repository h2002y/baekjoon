#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int S, K, H, sum;
    cin >> S >> K >> H;
    sum = S + K + H;
    if (sum >= 100) cout << "OK\n";
    else {
        int minU = min(S, min(K, H));
        if (S == minU) cout << "Soongsil\n";
        else if (K == minU) cout << "Korea\n";
        else cout << "Hanyang\n";
    }
    return 0;
}