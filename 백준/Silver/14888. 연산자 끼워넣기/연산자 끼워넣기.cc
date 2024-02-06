#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;
int maxAdd, maxSub, maxMul, maxDiv, maxResult = -1000000001, minResult = 1000000001;

void recurse(int cnt, int result, int a, int s, int m, int d) {
    if (cnt == N) {
        if (maxResult < result) maxResult = result;
        if (minResult > result) minResult = result;
        return; 
    }
    if (a < maxAdd) 
        recurse(cnt + 1, result + A[cnt], a + 1, s, m, d);
    if (s < maxSub)
        recurse(cnt + 1, result - A[cnt], a, s + 1, m, d);
    if (m < maxMul)
        recurse(cnt + 1, result * A[cnt], a, s, m + 1, d);
    if (d < maxDiv)
        recurse(cnt + 1, result / A[cnt], a, s, m, d + 1);
}

int main () {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    cin >> maxAdd >> maxSub >> maxMul >> maxDiv;
    recurse(1, A[0], 0, 0, 0, 0);
    cout << maxResult << "\n" << minResult << "\n";
    return 0;
}