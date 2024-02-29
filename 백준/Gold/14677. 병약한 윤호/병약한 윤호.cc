#include <iostream>
#include <vector>
using namespace std;

int N, maxSum;
char meal[3] = {'B', 'L', 'D'};
string pills;
vector<vector<int>> dp;

int recur(int left, int right, int curr)
{
    // 더 먹을 수 있는 약X
    if (left > right)
        return 0;
    // 이미 계산한 dp 리턴
    if (dp[left][right] != -1)
        return dp[left][right];
    // 현재 상태에서 먹을 수 있는 약 구하기
    dp[left][right] = 0;
    // 왼쪽 약을 먹었을 때
    if (pills[left] == meal[curr])
    {
        int next = curr + 1;
        if (next == 3)
            next = 0;
        dp[left][right] = max(dp[left][right], recur(left + 1, right, next) + 1);
    }
    // 오른쪽 약을 먹었을 때
    if (pills[right] == meal[curr])
    {
        int next = curr + 1;
        if (next == 3)
            next = 0;
        dp[left][right] = max(dp[left][right], recur(left, right - 1, next) + 1);
    }
    // 계산한 dp 리턴
    return dp[left][right];
}

int main()
{
    cin >> N >> pills;
    vector<int> v(N * 3, -1);
    dp.resize(N * 3, v);
    cout << recur(0, 3 * N - 1, 0) << "\n";
    return 0;
}