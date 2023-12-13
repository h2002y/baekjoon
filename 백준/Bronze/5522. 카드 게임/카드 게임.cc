#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        int N;
        cin >> N;
        sum += N;
    }
    cout << sum << "\n";
    return 0;
}