#include <iostream>
using namespace std;

int main () {
    int N;
    while (1) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j)
                cout << "*";
            cout << "\n";
        }
    }
    return 0;
}