#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 완탐 후 최적화(그리디)
int main() {
    int N;
    cin >> N;
    vector<int> houses(N);
    for(int i = 0; i < N; i++)
        cin >> houses[i];
    sort(houses.begin(), houses.end());
    int mid;
    if(N % 2 == 0) mid = N / 2 - 1;
    else mid = N / 2;
    cout << houses[mid] << "\n";
    return 0;
}