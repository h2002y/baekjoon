#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N, cnt = 0;
    cin >> N;
    if (N == 1) {
        cout <<"0\n";
        return 0;
    }
    vector<bool> isPrime (N + 1, 1);
    vector<int> primes;

    for (int i = 2; i <= N; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
            for (int j = i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    int left = 0, right = 0, currSum = 0;
    while (right <= primes.size()) {
        if (currSum < N)
            currSum += primes[right++];
        else {
            if(currSum == N) ++cnt;
            currSum -= primes[left++];
        }
    }
    cout << cnt << "\n";
    return 0;
}