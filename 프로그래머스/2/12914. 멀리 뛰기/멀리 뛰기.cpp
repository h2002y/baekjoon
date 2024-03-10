#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> dp(n + 1);
    long long answer = 0;
    dp[1] = 1; dp[2] = 2;
    int curr = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] > 1234567) dp[i] %= 1234567;
    }
    return dp[n];
}