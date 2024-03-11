#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    vector<pair<int, int>> t;
    int curr = -1, cnt = 0;
    for (int i = 0; i < tangerine.size(); ++i) {
        if (tangerine[i] == curr)
            ++cnt;
        else if (tangerine[i] != curr) {
            t.push_back(make_pair(curr, cnt));
            curr = tangerine[i];
            cnt = 1;
        }
        if (i == tangerine.size() - 1)
            t.push_back(make_pair(curr, cnt));
    }
    sort (t.begin(), t.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second > b.second;
    });

    int sum = 0;
    for (int i = 0; i < t.size(); ++i) {
        sum += t[i].second;
        if (sum >= k) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}