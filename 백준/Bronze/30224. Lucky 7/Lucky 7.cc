#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    bool isSeven = false, isDivide = false;
    cin >> N;
    string NtoString = to_string(N);
    for(char c : NtoString)
        if(c == '7') isSeven = true;
    if(N % 7 == 0) isDivide = true;
    if(isSeven && isDivide) cout << "3\n";
    else if(isSeven && !isDivide) cout << "2\n";
    else if(!isSeven && isDivide) cout << "1\n";
    else cout << "0\n";
    return 0;
}