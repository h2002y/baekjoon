#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cout << fixed;
    if(N % 4 == 0) cout.precision(1);
    else cout.precision(2);
    cout << (float)N / 4 << "\n";
    return 0;
}