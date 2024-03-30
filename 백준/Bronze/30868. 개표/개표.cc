#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int votes;
        cin >> votes;
        for (int j = 1; j <= (votes / 5); ++j)
            cout << "++++ ";
        for (int j = 1; j <= (votes % 5); ++j)
            cout << "|";
        cout << "\n";
    }
    return 0;
}