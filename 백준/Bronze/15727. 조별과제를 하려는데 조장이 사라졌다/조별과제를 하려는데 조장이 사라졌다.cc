#include <iostream>
using namespace std;

int main() {
    int L, t;
    cin >> L;
    t = L / 5;
    if(L % 5 != 0) ++t;
    cout << t << "\n";
    return 0;
}