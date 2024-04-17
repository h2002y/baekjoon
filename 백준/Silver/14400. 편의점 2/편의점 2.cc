#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long minDist = 0;
    int N, midX, midY;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    midX = X[N / 2];
    midY = Y[N / 2];
    for (int i = 0; i < N; ++i)
        minDist += abs(X[i] - midX) + abs(Y[i] - midY);
    cout << minDist << "\n";
    return 0;
}