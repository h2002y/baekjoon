#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BS (int left, int right, vector<int> &arr) {
    if(abs(arr[left] + arr[right]) % 2 == 1) return 0;
    int finds = (arr[left] + arr[right]) / 2;

    while (left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == finds) return 1; 
        else if (arr[mid] < finds) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        int N, cnt = 0;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; ++i)
            cin >> v[i];
        sort(v.begin(), v.end());
        for (int l = 0; l < N; ++l)
            for (int r = l + 1; r < N; ++r)
                cnt += BS(l, r, v);
        cout << cnt << "\n";
    }
    return 0;
}