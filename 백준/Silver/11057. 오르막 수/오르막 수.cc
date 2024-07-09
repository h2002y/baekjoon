#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int> v(10);
    vector<vector<int>> dp(N, v);
    for (int i = 0; i < 10; ++i)
        dp[0][i] = 1;

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = j; k < 10; ++k) {
                dp[i + 1][k] += dp[i][j];
                if (dp[i + 1][k] > 10007) dp[i + 1][k] %= 10007;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += dp[N - 1][i];
        if (sum > 10007) sum %= 10007;
    }

    cout << sum << "\n";
    
    return 0;
}