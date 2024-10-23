#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> arr;

bool binarySearch(long long input) {
    long long left = 0, right = arr.size() -1;
    while(left <= right) {
        long long mid = (left + right) / 2;
        if (arr[mid] == input) return true;
        if (arr[mid] < input) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int input;
        cin >> input;
        cout << binarySearch(input) << "\n";
    }
    return 0;
}