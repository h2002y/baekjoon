#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s, tmp = "";
        cin >> s;
        tmp += s[0];
        for (int j = 1; j < s.length(); ++j) 
            if(s[j - 1] != s[j]) 
                tmp += s[j];
        cout << tmp << "\n";
    }
    return 0;
}