#include <iostream>
using namespace std;

int main() {
  int N, cnt = 0;
  cin >> N;
  for(int A = 1; A <= 1000; A++) 
    for(int B = 1; B <= A; B++) 
      if( A * A == B * B + N) 
        cnt++;
  cout << cnt << "\n";
  return 0;
}