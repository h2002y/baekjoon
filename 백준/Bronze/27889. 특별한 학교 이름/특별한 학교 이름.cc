#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> m;
    m["NLCS"] = "North London Collegiate School";
    m["BHA"] = "Branksome Hall Asia";
    m["KIS"] = "Korea International School";
    m["SJA"] = "St. Johnsbury Academy";
    string input;
    cin >> input;
    cout << m[input] << "\n";
    return 0;
}