#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int testCase;
    cin >> testCase;
    for(int tc = 0; tc < testCase; ++tc) {
        long long N;
        bool isPrime = true;
        cin >> N;
        if(N % 2 == 0) {
            cout << "NO\n";
            isPrime = false;
            continue;
        }
        for(long long div = 3; div <= 1000000; div += 2) {
            if(N % div == 0 && div <= 1000000) {
                cout <<"NO\n";
                isPrime = false;
                break;
            }
        }
        if(isPrime) cout << "YES\n";
    }
    return 0;
}