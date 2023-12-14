#include <iostream>
using namespace std;

int main() {
    string input;
    cin >> input;
    for(int i = input.length() - 1; i >= 0; --i)
        cout << input[i];
    return 0;
}