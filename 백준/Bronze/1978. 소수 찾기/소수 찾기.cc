#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<bool> isPrime(1001, true);
    int cnt = 0, N;
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i * i <= 1000; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= 1000; j += i)
            isPrime[j] = false;
    }
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (isPrime[num]) ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}