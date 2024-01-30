#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, W, H, cnt = 0;
    cin >> N >> W >> H;
    vector<pair<int, int>> v(N);
    set<pair<int, int>> s;
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
        s.insert(v[i]);
    }
    for (int i = 0; i < N; ++i) {
        int x = v[i].first, y = v[i].second;
        if (s.find({x + W, y}) == s.end()) continue;
        if (s.find({x, y + H}) == s.end()) continue;
        if (s.find({x + W, y + H}) == s.end()) continue;
        ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}