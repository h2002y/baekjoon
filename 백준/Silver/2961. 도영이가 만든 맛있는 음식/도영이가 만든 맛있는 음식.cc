#include <iostream>
#include <vector>
using namespace std;

int N, minTaste = 1000000000;
vector<int> S, B;

void recurse(int idx, int s, int b) {
    if (s > 1 && b > 0) {
        int taste = abs(s - b);
        if (taste < minTaste) minTaste = taste;
    }
    if (idx == N) return;
    recurse(idx + 1, s, b);
    recurse(idx + 1, s * S[idx], b + B[idx]);
}

int main () {
    cin >> N;
    S.resize(N); B.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i] >> B[i];
    recurse(0, 1, 0);
    cout << minTaste << "\n";
    return 0;
}