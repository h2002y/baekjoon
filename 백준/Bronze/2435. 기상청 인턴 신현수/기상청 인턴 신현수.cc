#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K, maxSum, sum = 0;
    cin >> N >> K;
    vector<int> numbers(N);
    for(int i = 0; i < N; i++){
        cin >> numbers[i];
        if(i < K)
            sum += numbers[i];
    }
    maxSum = sum;
    int left = 0, right = K - 1;
    while(true) {
        sum -= numbers[left++];
        ++right;
        if(right == N) break;
        sum += numbers[right];
        if(sum > maxSum) maxSum = sum;
    }
    cout << maxSum << "\n";
    return 0;
}