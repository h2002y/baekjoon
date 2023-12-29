#include <iostream>
using namespace std;

int main () {
    for (int i = 0; i < 8; ++i) {
        int bit;
        cin >> bit;
        if(bit > 1) {
            cout << "F\n";
            return 0;
        }
    }
    cout << "S\n";
    return 0;
}