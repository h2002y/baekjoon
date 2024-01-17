#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    int sum = v[0], left = 0, right = 0, cnt = 0;
    while(right < N) {
        if (sum == M) ++cnt;
        if (sum <= M) 
            sum += v[++right];
        else 
            sum -= v[left++];
    }
    cout << cnt << "\n";
    return 0;
}