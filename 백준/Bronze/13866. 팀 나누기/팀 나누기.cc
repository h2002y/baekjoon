#include <iostream>
using namespace std;

int main() {
    int p[4];
    int sum = 0, minDiff = 1000000000;
    for (int i = 0; i < 4; ++i) {
        cin >> p[i];
        sum += p[i];
    }
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 4; ++j) {
            int t1 = p[i] + p[j], t2 = sum - t1;
            if (abs(t1 - t2) < minDiff)
                minDiff = abs(t1 - t2);
        }
    cout << minDiff << "\n";
    
    return 0;
}