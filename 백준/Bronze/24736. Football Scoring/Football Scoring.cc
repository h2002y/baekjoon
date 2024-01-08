#include <iostream>
using namespace std;

int main () {
    int visit = 0, home = 0, T, F, S, P, C;
    cin >> T >> F >> S >> P >> C;
    visit = T * 6 + F * 3 + S * 2 + P + C * 2;
    cin >> T >> F >> S >> P >> C;
    home = T * 6 + F * 3 + S * 2 + P + C * 2;
    cout << visit << " " << home << "\n";
    return 0;
}