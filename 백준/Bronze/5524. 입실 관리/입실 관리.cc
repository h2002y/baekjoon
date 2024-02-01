#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); ++j)
            if (input[j] >= 'A' && input[j] <= 'Z')
                input[j] += 32;
        cout << input << "\n";
    }
    return 0;
}