#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string label = "WelcomeToSMUPC";
    cout << label[(N - 1) % 14] << "\n";
    return 0;
}