#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> v(26);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (!(s[i] >= 'a' && s[i] <= 'z')) continue;
        v[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i)
       cout << v[i] << " ";
    cout << "\n";
    return 0;
}