#include <iostream>
#include <vector>
using namespace std;

int N, minCoins = 10001;
vector<bool> isVisited;
vector<int> costs, order;
vector<vector<pair<int, int>>> sales;

void recurse (int idx) {
    if (idx == N) {
        vector<int> tmpCosts = costs;
        vector<bool> isBought(N);
        for (int i = 0; i < N; ++i) { // order
            for (int j = 0; j < sales[order[i]].size(); ++j) {
                int potionIdx = sales[order[i]][j].first - 1;
                int sale = sales[order[i]][j].second;
                if (isBought[potionIdx]) continue; // 이미 구매한 포션이면 스킵
                tmpCosts[potionIdx] -= sale;
                if (tmpCosts[potionIdx] < 1) tmpCosts[potionIdx] = 1;
            }
            isBought[order[i]] = true;
        }
        int coins = 0;
        for (int i = 0; i < N; ++i)
            coins += tmpCosts[i];
        if (coins < minCoins) minCoins = coins;
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (isVisited[i]) continue;
        isVisited[i] = true;
        order[idx] = i;
        recurse(idx + 1);
        order[idx] = 0;
        isVisited[i] = false;
    }
}

int main () {
    cin >> N;
    costs.resize(N);
    order.resize(N);
    isVisited.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> costs[i];
    vector<pair<int, int>> v;
    sales.resize(N, v);
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        for (int j = 0; j < p; ++j) {
            int idx, sale;
            cin >> idx >> sale;
            sales[i].push_back(make_pair(idx, sale));
        } 
    }
    recurse(0);
    cout << minCoins << "\n";
    return 0;
}