#include <iostream>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    long long left = 0, right = 0, maxDrink = 0;
    cin >> N >> K;
    vector<int> drinks(N);
    for (int i = 0; i < N; ++i) {
        cin >> drinks[i];
        if (drinks[i] > right) right = drinks[i];
    }
    while (left <= right) {
        long long mid = (left + right) / 2;
        int cnt = 0;
        if (mid == 0) {
            for (int i = 0; i < N; ++i)
                if (drinks[i] > mid) ++cnt;
        } else {
            for (int i = 0; i < N; ++i)
                cnt += (drinks[i] / mid);
        }
        if (cnt >= K) {
            if (mid > maxDrink) maxDrink = mid;
            left = mid + 1;
        } else
            right = mid - 1;
    }
    cout << maxDrink << "\n";
    return 0;
}