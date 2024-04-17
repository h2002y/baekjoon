#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> coins(N), dp(K + 1);
    dp[0] = 1;
    for (int i = 0; i < N; ++i)
        cin >> coins[i];
    for (int i = 0; i < N; ++i)
        for (int j = coins[i]; j <= K; ++j)
            dp[j] += dp[j - coins[i]];
    cout << dp[K] << "\n";
    return 0;
}