#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  vector<int> liquids(N);
  for(int i = 0; i < N; i++)
    cin >> liquids[i];
  int start = 0, end = N - 1;
  int liq1, liq2, liqMin = 2000000001;
  while(start < N && end >= 0 && start < end) {
    int lLeft = liquids[start];
    int lRight = liquids[end];
    int lAbs = abs(lLeft + lRight);
    if(lAbs == 0) {
      cout << lLeft <<" " << lRight <<"\n";
      return 0;
    } else {
      if(lAbs < liqMin) {
        liqMin = lAbs;
        liq1 = lLeft;
        liq2 = lRight;
      }

      if(lLeft + lRight < 0)
        ++start;
      else --end;
    }
  }
  cout << liq1 << " " << liq2 << "\n";
  return 0;
}