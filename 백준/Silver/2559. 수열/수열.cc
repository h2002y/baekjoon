#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> v(N + 1);
    v[0] = 0;
    for (int i = 1; i <= N; i++){
        int num;
        cin >> num;
        v[i] = v[i - 1] + num;
    }
    int maxSum = v[K];
    for (int i = K + 1; i <= N; i++)
        maxSum = max(maxSum, v[i] - v[i - K]);
    cout << maxSum << "\n";
    return 0;
}