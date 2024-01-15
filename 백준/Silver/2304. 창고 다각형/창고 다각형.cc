#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N, area = 0;
    cin >> N;
    vector<int> p(1001);
    for (int i  = 0; i < N; ++i) {
        int L, H;
        cin >> L >> H;
        p[L] = H;
    }
    for (int i = 1; i <= 1000; ++i) {
        int left = 0, right = 0, minH;
        for (int l = 1; l <= i; ++l)
            if (left < p[l]) left = p[l];
        for (int r = i; r <= 1000; ++r)
            if (right < p[r]) right = p[r];
        minH = min(left, right);
        area += minH;
    }
    cout << area << "\n";
    return 0;
}