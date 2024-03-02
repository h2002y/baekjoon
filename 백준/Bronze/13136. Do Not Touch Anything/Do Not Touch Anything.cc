#include <iostream>
using namespace std;

int main () {
    long long R, C, N;
    cin >> R >> C >> N;
    long long r = R / N, c = C / N;
    if (R % N != 0) ++r;
    if (C % N != 0) ++c;
    cout << r * c << "\n";
    
    return 0;
}