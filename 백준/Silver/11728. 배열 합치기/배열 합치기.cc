#include <iostream>
#include <vector>

using namespace std;
int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> n(N), m(M);
    for (int i = 0; i < N; ++i)
        cin >> n[i];
    for (int i = 0; i < M; ++i)
        cin >> m[i];
    int nIndex = 0, mIndex = 0;
    while(nIndex < N && mIndex < M) {
        if (n[nIndex] <= m[mIndex]) 
            cout << n[nIndex++] << " ";
        else 
            cout << m[mIndex++] << " ";
    }
    while(nIndex < N) {
        cout << n[nIndex++] << " ";
    }
    while(mIndex < M) {
        cout << m[mIndex++] << " ";
    }
    return 0;
}