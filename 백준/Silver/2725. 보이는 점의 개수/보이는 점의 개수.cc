#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main () {
    int dp[1001];
    dp[1] = 3;
    for (int i = 2; i <= 1000; ++i) {
        int cnt = 0;
        for (int j = 1; j < i; ++j)
            if (gcd(i, j) == 1) ++cnt;
        dp[i] = dp[i - 1] + cnt * 2;
    }
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }
    return 0;
}