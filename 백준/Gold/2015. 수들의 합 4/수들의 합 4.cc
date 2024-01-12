#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, K, cnt = 0;
    map<long long, long long> m;
    cin >> N >> K;
    vector<long long> prefix_sum(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
        if (prefix_sum[i] == K) ++cnt;
    }
    for (int i = 1; i <= N; ++i) {
        cnt += m[prefix_sum[i] - K];
        m[prefix_sum[i]]++;
    }
    cout << cnt << "\n";
    return 0;
}

/*
입력: 
    4 0
    2 -2 2 -2

누적합 arr = 2 0 2 0
첫번째 for문에서 cnt = 2
cnt += m[2 - K] = m[2 - 0] = m[2] = 0 => cnt = 2
m[2]++;

cnt += m[0 - K] = m[0 - 0] = m[0] => cnt = 2
m[0]++;

cnt += m[2 - K] = m[2 - 0] = m[2] = 1 => cnt = 3
m[2]++;

cnt += m[0 - K] = m[0 - 0] = m[0] = 1 => cnt = 4;
m[0]++;

출력 = 4 */