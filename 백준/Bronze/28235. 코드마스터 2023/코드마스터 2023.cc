#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> m;
    m["SONGDO"] = "HIGHSCHOOL";
    m["CODE"] = "MASTER";
    m["2023"] = "0611";
    m["ALGORITHM"] = "CONTEST";
    string s;
    cin >> s;
    cout << m[s] << "\n";
    return 0;
}