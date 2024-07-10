#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<bool> isPrime(N + 1, true);

    int cnt = 0;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            isPrime[i] = false;
            ++cnt;
            if (cnt == K) {
                cout << i << "\n";
                break;
            }
            for (int j = i * i; j <= N; j += i) {
                if (!isPrime[j]) continue;
                isPrime[j] = false;
                ++cnt;
                if (cnt == K) {
                    cout << j << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}