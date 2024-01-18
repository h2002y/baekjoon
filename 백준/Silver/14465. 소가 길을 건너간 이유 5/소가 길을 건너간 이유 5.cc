#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N, K, B, minBroken;
    cin >> N >> K >> B;
    vector<bool> traffic(N + 1, true);
    for (int i = 0; i < B; ++i) {
        int broken;
        cin >> broken;
        traffic[broken] = false;
    }
    int currBroken = 0, left = 1, right = K;
    for (int i = 1; i <= K; i++)
        if (!traffic[i]) ++currBroken;
    minBroken = currBroken;
    while (right < N) {
        if (!traffic[left++]) --currBroken;
        if (!traffic[++right]) ++currBroken;
        if (currBroken < minBroken) minBroken = currBroken;
    }
    cout << minBroken << "\n";
    return 0;
}