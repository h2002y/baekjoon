#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
vector<int> v;
set<int> s;

void recurse(int idx, int sum) {
    if (sum > 0) s.insert(sum);
    if (idx == N) return;
    recurse(idx + 1, sum + v[idx]);
    recurse(idx + 1, sum);
}

int main () {
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    recurse(0, 0);
    for (int i = 1; i <= 2000000; ++i) {
        if (s.find(i) == s.end()) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}