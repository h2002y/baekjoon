#include <iostream>
#include <vector>
using namespace std;

int N, M, K, keys, maxQuest;
vector<bool> isAllo;
vector<vector<int>> quests;

void recurse(int idx, int cnt) {
    if (cnt == N) {
        int avail = 0;
        for (int i = 0; i < M; ++i) {
            bool isAvail = true;
            for (int j = 0; j < K; ++j) {
                if(!isAllo[quests[i][j]]) {
                    isAvail = false;
                    break;
                }
            }
            if (isAvail) ++avail;
        }
        if (avail > maxQuest) maxQuest = avail;
    }
    if (idx == keys + 1) return;
    recurse(idx + 1, cnt);
    isAllo[idx] = true;
    recurse(idx + 1, cnt + 1);
    isAllo[idx] = false;
}

int main () {
    cin >> N >> M >> K;
    keys = N * 2 + 1;
    isAllo.resize(keys);
    vector<int> v(K);
    quests.resize(M, v);
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < K; ++j)
            cin >> quests[i][j];
    recurse(1, 0);
    cout << maxQuest << "\n";
    return 0;
}