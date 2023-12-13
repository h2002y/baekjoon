#include <iostream>
using namespace std;

int main() {
    int P1, P2 ,P3;
    cin >> P1 >> P2 >> P3;
    if(P1 > P2 && P1 > P3)
        if(P2 > P3) cout << P2 << "\n";
        else cout << P3 << "\n";
    else if(P2 > P1 && P2 > P3)
        if(P1 > P3) cout << P1 << "\n";
        else cout << P3 << "\n";
    else
        if(P1 > P2) cout << P1 << "\n";
        else cout << P2 << "\n";
    return 0;
}