#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> nums;
vector<vector<long long>> dp;

long long recur(int sum, int index)
{
    if (sum < 0 || sum > 20)
        return 0;

    if (index == N - 1)
    {
        if (sum == nums[N - 1])
            return 1;
        else
            return 0;
    }

    if (dp[index][sum] != -1)
        return dp[index][sum];

    long long cnt = 0;
    cnt += recur(sum + nums[index], index + 1);
    cnt += recur(sum - nums[index], index + 1);
    dp[index][sum] = cnt;
    return dp[index][sum];
}

int main()
{
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    vector<long long> v(21, -1);
    dp.resize(N, v);
    cout << recur(nums[0], 1) << "\n";
    return 0;
}