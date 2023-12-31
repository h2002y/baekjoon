#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if(s.length() >= 6 && s.length() <= 9) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}