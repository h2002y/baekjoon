#include <iostream>
#include <vector>
using namespace std;

// G = c^2 - o^2 = (c + o)(c - o)
int main () {
    int G, old = 1, curr = 2;
    cin >> G;
    bool isExist = false;
    while (G > curr) {
        if (G / (old + curr) == curr - old) {
            if (G % (old + curr) == 0) {
                cout << curr << "\n";
                isExist = true;
            }
            ++curr;
        } else if (G / (old + curr) < curr - old)
            ++old;
        else if (G / (old + curr) > curr - old)
            ++curr;
        if (curr == old) ++curr;
    }
    if (!isExist) cout << "-1\n";
    return 0;
}