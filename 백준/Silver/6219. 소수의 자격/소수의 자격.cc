#include <iostream>
#include <vector>
using namespace std;

int main () {
    int A, B, D, cnt = 0;
    cin >> A >> B >> D;
    vector<bool> isPrime(B + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= B; ++i) {
        if(!isPrime[i]) continue;
        for (long long j = i * i; j <= B; j = j + i)
            isPrime[j] = false;
    }
    for (int i = A; i <= B; ++i) {
        if (isPrime[i]) {
            int num = i;
            while (num != 0) {
                if (num % 10 == D) {
                    ++cnt;
                    break;
                }
                num /= 10;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}