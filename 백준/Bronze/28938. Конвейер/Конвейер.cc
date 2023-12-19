#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    if(sum < 0) cout << "Left\n";
    else if (sum == 0) cout << "Stay\n";
    else cout << "Right\n";
    return 0;
}