#include <iostream>
#include <vector>
using namespace std;

int cnt;
int answers [10];

void recurse(int idx, int correct, int prev, int pprev) {
    if (idx == 10) {
        if (correct >= 5) ++cnt;
        return;
    } 
    for (int i = 1; i <= 5; ++i) {
        if (prev == i && pprev == i) continue;
        if (i == answers[idx]) recurse(idx + 1, correct + 1, i, prev);
        else recurse(idx + 1, correct, i, prev);
    }
}

int main () {
    for (int i = 0; i < 10; ++i)
        cin >> answers[i];
    recurse(0, 0, 0, 0);
    cout << cnt << "\n";
    return 0;
}