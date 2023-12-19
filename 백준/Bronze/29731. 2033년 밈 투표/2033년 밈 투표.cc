#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> s;
    s.insert("Never gonna give you up");
    s.insert("Never gonna let you down");
    s.insert("Never gonna run around and desert you");
    s.insert("Never gonna make you cry");
    s.insert("Never gonna say goodbye");
    s.insert("Never gonna tell a lie and hurt you");
    s.insert("Never gonna stop");
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        string input;
        getline(cin, input);
        if(s.find(input) == s.end()) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}