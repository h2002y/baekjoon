#include <iostream>
#include <map>
using namespace std;

int main() {
    map<char, string> m;
    m['M'] = "MatKor";
    m['W'] = "WiCys";
    m['C'] = "CyKor";
    m['A'] = "AlKor";
    m['$'] = "$clear";
    char c;
    cin >> c;
    cout << m[c] << "\n";
    return 0;
}