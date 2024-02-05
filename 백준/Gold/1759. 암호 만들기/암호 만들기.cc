#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> words;

void recurse(int cnt, int idx, int vowels, int cons, string s) {
    if(cnt == L) {
        if (vowels > 0 && cons > 1)
            cout << s << "\n";
        return;
    }
    if (cnt < L && idx == C) return;
    if (words[idx] == 'a' || words[idx] == 'e' || words[idx] == 'i' || words[idx] == 'o' || words[idx] == 'u')
        recurse(cnt + 1, idx + 1, vowels + 1, cons, s + words[idx]);
    else recurse(cnt + 1, idx + 1, vowels, cons + 1, s + words[idx]);
    recurse(cnt, idx + 1, vowels, cons, s);
}

int main () {
    cin >> L >> C;
    words.resize(C);
    for (int i = 0; i < C; ++i)
        cin >> words[i];
    sort(words.begin(), words.end());
    string s = "";
    recurse(0, 0, 0, 0, s);
    return 0;
}