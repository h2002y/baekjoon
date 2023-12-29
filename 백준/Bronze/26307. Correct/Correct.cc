#include <iostream>
using namespace std;

int main () {
    int h, m, total;
    cin >> h >> m;
    total = (h - 9) * 60 + m;
    cout << total << "\n";
    return 0;
}