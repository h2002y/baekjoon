#include <iostream>
using namespace std;

int main() {
    int sum  = 0;
    for(int i = 0; i < 6; i++) {
        int input;
        cin >> input;
        sum += input;
    }
    cout << sum * 5 << "\n";
    return 0;
}