#include <iostream>
#include <vector>
using namespace std;

int N, S, cnt;
vector<int> nums;

void recurse(int curr, int sum) {
    if (curr == N) return;
    recurse(curr + 1, sum);
    sum += nums[curr];
    if (sum == S) ++cnt;
    recurse(curr + 1, sum);

}

int main () {
    cin >> N >> S;
    nums.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    recurse(0, 0);
    cout << cnt << "\n";
    return 0;
}