#include <iostream>
using namespace std;

int main() {
    string input;
    cin >> input;
    for(char c : input)
        cout << (char)toupper(c);
    cout << "\n";
    return 0;
}