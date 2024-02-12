#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, minCost = 100000;
int minNu[4], sumNu[5] = {0, 0, 0, 0, 0};
vector<vector<int>> nu;
string idxAnswer;

void recurse (int idx, string s) {
    if (idx > 0 && s != "") {
        if (sumNu[0] >= minNu[0] && sumNu[1] >= minNu[1] && sumNu[2] >= minNu[2] && sumNu[3] >= minNu[3] && sumNu[4] < minCost) {
            minCost = sumNu[4];
            idxAnswer = s;
        }
    }
    if (idx == N) return;
    for (int i = 0; i < 5; ++i)
        sumNu[i] += nu[idx][i];
    recurse(idx + 1, s + to_string(idx + 1) + " ");
    for (int i = 0; i < 5; ++i)
        sumNu[i] -= nu[idx][i];
    recurse(idx + 1, s);
}

int main () {
    cin >> N;
    for (int i = 0; i < 4; ++i)
        cin >> minNu[i];
    vector<int> tmp(5);
    nu.resize(N, tmp);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> nu[i][j];
    string s = "";
    recurse(0, s);

    if (minCost == 100000) {
        cout << "-1\n";
        return 0;
    }

    cout << minCost << "\n" << idxAnswer << "\n";
    return 0;
}