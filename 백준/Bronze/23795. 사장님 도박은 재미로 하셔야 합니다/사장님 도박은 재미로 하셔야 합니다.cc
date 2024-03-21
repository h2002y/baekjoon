#include <iostream>
using namespace std;

int main () {
    int N, sum = 0;
    while (true) {
        cin >> N;
        if (N == -1) break;
        sum += N;
    }
    cout << sum << "\n";
    return 0;
}