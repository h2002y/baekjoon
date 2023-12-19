#include <iostream>
using namespace std;

int main() {
    int Max = 0, Mel = 0, m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    Max = m1 * 3 + m2 * 20 + m3 * 120;
    cin >> m1 >> m2 >> m3;
    Mel = m1 * 3 + m2 * 20 + m3 * 120;
    if(Max > Mel) cout << "Max\n";
    else if (Max < Mel) cout << "Mel\n";
    else cout << "Draw\n";
    return 0;
}