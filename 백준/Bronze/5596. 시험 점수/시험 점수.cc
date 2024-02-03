#include <iostream>
using namespace std;

int main () {
    int S = 0, T = 0;
    for (int i = 0; i < 4; ++i) {
        int score;
        cin >> score;
        S += score;
    }
    for (int i = 0; i < 4; ++i) {
        int score;
        cin >> score;
        T += score;
    }
    if (S >= T) cout << S << "\n";
    else cout << T << "\n";
}