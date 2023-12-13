#include <iostream>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for(int tc = 0; tc < testCase; ++tc) {
        int A, B;
        cin >> A >> B;
        cout << A + B << "\n";
    }
    return 0;
}