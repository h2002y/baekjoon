#include <iostream>
using namespace std;

int main() {
    int regular, small, cupcakes;
    cin >> regular >> small;
    cupcakes = regular * 8 + small * 3;
    cout << cupcakes - 28 << "\n";
    return 0;
}