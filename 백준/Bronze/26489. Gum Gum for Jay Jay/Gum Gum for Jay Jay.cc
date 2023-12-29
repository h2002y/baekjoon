#include <iostream>
using namespace std;

int main () {
    string s;
    int cnt = 0;
    while (cin >> s)
        if(s == "for") cnt++;
    cout << cnt << "\n"; 
    return 0;
}