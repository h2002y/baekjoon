#include <iostream>
using namespace std;

int main () {
    int N;
    string s;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); ++j) {
            if (input[j] == 'S') {
                s = input;
                break;
            }
        }
    }
    cout << s << "\n";
    return 0;
}