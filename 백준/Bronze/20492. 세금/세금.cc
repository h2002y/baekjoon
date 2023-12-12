#include <iostream>
using namespace std;

int main() {
    int N, first, second;
    cin >> N;
    first = N * 78 / 100;
    second = (N * 80 / 100) + ((N * 20 / 100) * 78 / 100);
    cout << first << " " << second<<"\n";
    return 0;
}