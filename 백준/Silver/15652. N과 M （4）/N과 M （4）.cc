#include <iostream>
#include <vector>
using namespace std;

int N, M;

void recurse(int cnt, int curr, vector<int> v) {
    if (cnt == M) {
        for (int i = 0; i < cnt; ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = curr; i <= N; ++i) {
        v[cnt] = i;
        recurse(cnt + 1, i, v);
        v[cnt] = 0;
    }
}

int main()
{
    cin >> N >> M;
    vector<int> v(M);
    recurse(0, 1, v);
    return 0;
}