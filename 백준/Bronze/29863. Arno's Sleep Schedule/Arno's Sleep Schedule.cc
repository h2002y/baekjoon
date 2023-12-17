#include <iostream>
using namespace std;

int main () {
    int sleep, awake;
    cin >> sleep >> awake;
    if(sleep > 3) cout << (24 - sleep) + awake << "\n";
    else cout << awake - sleep << "\n";
    return 0;
}