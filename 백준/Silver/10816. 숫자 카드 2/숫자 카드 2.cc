#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; ++i)
        cin >> cards[i];
    cin >> M;
    sort(cards.begin(), cards.end());
    for (int i = 0; i < M; ++i) {
        int find;
        cin >> find;
        cout << upper_bound(cards.begin(), cards.end(), find) - lower_bound(cards.begin(), cards.end(), find) << " ";
    }
    return 0;
}