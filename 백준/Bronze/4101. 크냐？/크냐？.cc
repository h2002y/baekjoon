#include <iostream>
using namespace std;

int main() {
    while(1) {
        int N, M;
        cin >> N >> M;
        if(N == 0 & M == 0) break;
        N > M ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}