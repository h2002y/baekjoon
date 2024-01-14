#include <iostream>
using namespace std;

int main () {
    int N, cnt = 0;
    string S;
    cin >> N >> S;
    for (int i = 0; i < S.length(); ++i)
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') ++cnt;
    cout << cnt << "\n";
    return 0;
}