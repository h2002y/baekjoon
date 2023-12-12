#include <iostream>
using namespace std;

int main() {
    int tc = 1;
    while(1) {
        int N, input;
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; i++)
            cin >> input;
        cout << "Case " << tc++ << ": Sorting... done!\n";
    }
    return 0;
}