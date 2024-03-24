#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int A, B, C, D, E, F, sum = 0;
    cin >> A >> B >> C >> D >> E >> F;
    sum = A + B + C + D + E + F;
    int minS = 100, minG = 100;
    minS = min(minS, A);
    minS = min(minS, B);
    minS = min(minS, C);
    minS = min(minS, D);
    sum -= minS;
    minG = min(minG, E);
    minG = min(minG, F);
    sum -= minG;
    cout << sum << "\n";
}