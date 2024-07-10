#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int> ropes(N);
    for (int i = 0; i < N; ++i)
        cin >> ropes[i];
    sort(ropes.begin(), ropes.end(), greater<int>());
    
    int sum = 0;
    int maxWeight = 0;
    for (int i = 0; i < N; ++i) {
        int weight = ropes[i] * (i + 1);
        if (maxWeight < weight) maxWeight = weight;
    }
    cout << maxWeight << "\n";
    return 0;
}