#include <iostream>
using namespace std;

int main() {
    int N, sum = 0, result;
    cin >> N;
    for(int i = 1; i <= N; i++)
        sum += i;
    result = sum * sum;
    cout << sum << "\n" << result << "\n" << result << "\n";
    return 0;
}