#include <iostream>
using namespace std;

int main () {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        int input;
        cin >> input;
        sum += input;
    }
    cout << sum / 60 << "\n" << sum % 60 << "\n";
    return 0;
}