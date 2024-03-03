#include <iostream>
using namespace std;

int main () {
    int left, right;
    cin >> left >> right;
    if (left == 0 && right == 0) cout << "Not a moose\n";
    else if (left == right) cout << "Even " << left + right << "\n";
    else {
      cout << "Odd ";
      if (left < right) cout << right * 2 << "\n";
      else cout << left * 2 << "\n";
    }
    return 0;
}