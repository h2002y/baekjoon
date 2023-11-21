#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  for(int n1 = -1000; n1 <= 1000; ++n1) {
    if(n1 * n1 + (2 * A * n1) + B == 0) {
      for(int n2 = n1 + 1; n2 <= 1000; ++n2) {
        if(n2 * n2 + (2 * A * n2) + B == 0) {
          cout << n1 << " " << n2 << "\n";
          return 0;
        }
      }
      cout << n1 << "\n";
      return 0;
    }
  }
  return 0;
}