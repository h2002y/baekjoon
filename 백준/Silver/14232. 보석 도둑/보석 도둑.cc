#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, cnt = 0;
    cin >> N;
    vector<long long> jewels;
    for (long long i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            jewels.push_back(i);
            ++cnt;
            N /= i;
        }
    }
    if (N != 1) {
        cnt++;
        jewels.push_back(N);
    }
    cout << cnt << "\n";
    for (int i = 0; i < jewels.size(); ++i)
        cout << jewels[i] << " ";
    return 0;
}