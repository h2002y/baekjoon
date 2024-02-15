#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> days, profits, dp;

int recurse(int day) {
    if (day > N + 1) return -1500000000; // 날짜 초과하면 X
    if (day == N + 1) return 0; // N + 1이 되면 일을 더 할수 없음으로 0 리턴
    if (dp[day] != -1) return dp[day]; // dp를 한번만 계산
    dp[day] = max(recurse(day + days[day]) + profits[day], recurse(day + 1));
    return dp[day];
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    days.resize(N + 1); profits.resize(N + 1); dp.resize(N + 1, -1);
    for (int i = 1; i <= N; ++i)
        cin >> days[i] >> profits[i];
    int answer = recurse(1);
    cout << answer << "\n";
    return 0;
}