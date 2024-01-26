#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N, M, answer;
    cin >> N >> M;
    long long left = 1, right = 0;
    vector<int> jewels(M);
    for (int i = 0; i < M; ++i) {
        cin >> jewels[i];
        if (jewels[i] > right) right = jewels[i];
    }
    while (left <= right) {
        long long mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            cnt += jewels[i] / mid;
            if (jewels[i] % mid != 0) ++cnt;
        }
        if (cnt <= N) {
            answer = mid;
            right = mid - 1;
        } 
        else left = mid + 1;
    }
    cout << answer << "\n";
    return 0;
}