#include <iostream>
using namespace std;

int main () {
    int M, K;
    cin >> M >> K;
    if (M % K == 0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}