#include <iostream>
using namespace std;

int main() {
  int a, b, n, w;
  cin >> a >> b >> n >> w;
  int cnt = 0, goat = 0, sheep = 0;
  for(int i = 1; i < n; i++) {
    int currSheep = i, currGoat = n - i;
    int sum = currSheep * a + currGoat * b;
    if(sum == w) {
      cnt++;
      sheep = currSheep;
      goat = currGoat;
    }
  }
  if(cnt == 1)
    cout << sheep << " " << goat << "\n";
  else 
    cout << "-1\n";
  return 0;
}