#include <iostream>
using namespace std;

int main () {
    int N;
    string S;
    cin >> N >> S;
    for (int i = S.size() - 5; i < S.size(); ++i)
        cout << S[i];
    cout << "\n";
    return 0;
}