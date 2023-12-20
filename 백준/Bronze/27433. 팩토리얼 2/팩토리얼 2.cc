#include <iostream>
using namespace std;

int main() {
    int N;
    long long factorial = 1;
    cin >> N;
    for(int i = N; i > 1; --i)
        factorial *= i;
    cout << factorial << "\n";
    return 0;
}