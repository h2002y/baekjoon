#include <iostream>
using namespace std;

int main() {
    float W, H;
    cin >> W >> H;
    cout << fixed;
    cout.precision(1);
    cout << W * H / 2 << "\n";
    return 0;
}