#include <iostream>
using namespace std;

int main() {
    int first, end;
    cin >> first >> end;
    if(first >= (float)end / 2) cout << "E\n";
    else cout << "H\n";
    return 0;
}