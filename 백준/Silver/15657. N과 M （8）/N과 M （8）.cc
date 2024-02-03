#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;

void recurse(int cnt, int curr, vector<int> v) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = curr; i < N; ++i) {
        v[cnt] = nums[i];
        recurse(cnt + 1, i, v);
        v[cnt] = 0;
    }
}

int main () {
    cin >> N >> M;
    nums.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    vector<int> v(M);
    recurse(0, 0, v);
    return 0;
}