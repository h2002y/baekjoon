#include <iostream>
using namespace std;

int main () {
    int burger[3];
    int drink[2];
    for (int i = 0; i < 3; ++i)
        cin >> burger[i];
    for (int i = 0; i < 2; ++i)
        cin >> drink[i];
    int minPrice = 4001;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            int total = burger[i] + drink[j];
            if (total < minPrice) minPrice = total;
        }
    }
    cout << minPrice - 50 << "\n";
    return 0;
}