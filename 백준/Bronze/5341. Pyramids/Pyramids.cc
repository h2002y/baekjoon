#include <iostream>
using namespace std;

int main() {
    int N;
    while(1) {
        cin >> N;
        if(N == 0) break;
        int sum = N;
        for(int i = 1; i < N; ++i)
            sum += i;
        cout << sum << "\n";
    }
}