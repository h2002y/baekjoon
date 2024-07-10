#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N, C, maxDist = 0;
    cin >> N >> C;
    vector<int> homes(N);
    for (int i = 0; i < N; ++i)
        cin >> homes[i];
    sort(homes.begin(), homes.end());

    int left = 1, right = homes[N - 1];
    while(left <= right) {
        int mid = (left + right) / 2;

        // 첫 번째 공유기 설치
        int prevIdx = 0; // 이전 공유기를 설치한 집의 인덱스
        int prev = homes[0]; // 이전 공유기를 설치한 집의 좌표
        int currWifi = 1; // 현재 설치한 공유기 개수

        // 공유기 설치 작업
        for (int home = 1; home < N; ++home) {
            int next = homes[home];

            // 공유기 설치 가능
            if (next - prev >= mid) {
                prevIdx = home;
                prev = homes[home];
                ++currWifi;
            }
        }

        // C 이상의 공유기를 설치할 수 있으면 left = mid + 1
        if (currWifi >= C) {
            // C 이상의 공유기도 포함된다
            // C 초과해서 공유기를 설치해도 mid 설치 거리는 만족하기 때문
            if (mid > maxDist)
                maxDist = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << maxDist << "\n";

    return 0;
}