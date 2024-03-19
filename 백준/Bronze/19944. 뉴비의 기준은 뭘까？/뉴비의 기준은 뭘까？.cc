#include <iostream>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    if (M == 1 || M == 2) cout << "NEWBIE!\n";
    else if (N >= M) cout << "OLDBIE!\n";
    else cout << "TLE!\n";
    return 0;
}