#include <iostream>
using namespace std;

int main() {
  int A, B, C, N;
  cin >> A >> B >> C >> N;
  for(int room1 = 0; (room1 * A) <= N; ++room1) {
    for (int room2 = 0; (room1 * A) + (room2 * B) <= N; ++room2) {
      int studentsLeft = N - ((room1 * A) + (room2 * B));
      if(studentsLeft % C == 0) {
        cout << 1 << "\n";
        return 0;
      }
    }
  }
  cout << 0 << "\n";
  return 0;
}