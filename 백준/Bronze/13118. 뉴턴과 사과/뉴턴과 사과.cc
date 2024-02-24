#include <iostream>
using namespace std;

int main () {
    int ppl[4];
    int x, y, r;
    cin >> ppl[0] >> ppl[1] >> ppl[2] >> ppl[3] >> x >> y >> r;
    for (int i = 0; i < 4; ++i)
        if (ppl[i] == x) {
            cout << i + 1 << "\n";
            return 0;
        }
    cout << "0\n";
    return 0;
}