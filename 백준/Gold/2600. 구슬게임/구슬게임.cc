#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int B[3], K1[5], K2[5];
int maxK1, maxK2;
vector<vector<int>> dp;

int recur(int beeds1, int beeds2)
{
    if (dp[beeds1][beeds2] != -1)
        return dp[beeds1][beeds2];

    // K1 구슬 통에서 B[i]의 구슬을 가져간 후 다음 턴이 확정 승리가 아니라면 1 리턴
    for (int i = 0; i < 3; ++i)
    {
        if (beeds1 >= B[i] && !(recur(beeds1 - B[i], beeds2)))
        {
            dp[beeds1][beeds2] = 1;
            return dp[beeds1][beeds2];
        }
    }

    // K2 구슬 통에서 B[i]의 구슬을 가져간 후 다음 턴이 확정 승리가 아니라면 1 리턴
    for (int i = 0; i < 3; ++i)
    {
        if (beeds2 >= B[i] && !(recur(beeds1, beeds2 - B[i])))
        {
            dp[beeds1][beeds2] = 1;
            return dp[beeds1][beeds2];
        }
    }

    // 다음 턴이 모두 확정 승리이거나 구슬이 적어서 가져갈 수 없는 경우 0 리턴
    dp[beeds1][beeds2] = 0;
    return dp[beeds1][beeds2];
}

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        cin >> B[i];
    }
    for (int i = 0; i < 5; ++i)
    {
        cin >> K1[i] >> K2[i];
        maxK1 = max(maxK1, K1[i]);
        maxK2 = max(maxK2, K2[i]);
    }

    // dp 2차원 배열 -1 초기화
    vector<int> v(maxK2 + 1, -1);
    dp.resize(maxK1 + 1, v);

    // 가져갈 수 있는 구슬 만큼의 값만 남았다면 승리 => 1 초기화
    for (int i = 0; i < 3; ++i)
        dp[B[i]][0] = dp[0][B[i]] = 1;

    for (int i = 0; i < 5; ++i)
    {
        if (recur(K1[i], K2[i]))
            cout << "A\n";
        else
            cout << "B\n";
    }

    return 0;
}