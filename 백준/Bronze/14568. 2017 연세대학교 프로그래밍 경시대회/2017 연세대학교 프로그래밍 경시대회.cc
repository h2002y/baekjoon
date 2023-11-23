#include <iostream>
using namespace std;

int main() {
  int N, answer = 0;
  cin >> N;

  for (int c1 = 1; c1 < N; ++c1) {
    for (int c2 = c1 + 2; c2 < N; ++c2) {
      if(c1 + c2 >= N) break;
      int c3 = (N - (c1 + c2));
      if(c3 % 2 == 1) continue;
      if(c1 + c2 + c3 == N) 
        ++answer;
    }
  }

  cout << answer << "\n";
  return 0;
}