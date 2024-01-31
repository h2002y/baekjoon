#include <iostream>
#include <vector>
using namespace std;

static int N, M;

void recurse(int n, int m, int cnt, vector<int> v, int curr) {
    if (cnt == m) {
        for (int i = 0; i < m; ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = curr; i <= n; ++i) {
        v[cnt] = i;
        recurse(n, m, cnt + 1, v, i + 1);
        v[cnt] = 0;
    }
}

int main () {
    cin >> N >> M;
    vector<int> v(M);
    recurse(N, M, 0, v, 1);
    return 0;
}