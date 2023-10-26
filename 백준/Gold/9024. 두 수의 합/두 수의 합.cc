#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int testCase;
  cin >> testCase;
  for(int tc = 0; tc < testCase; tc++) {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for(int i = 0; i < N; i++)
      cin >> nums[i];
    sort(nums.begin(), nums.end());
    int cnt = 0, minAbs = 2000000001, left = 0, right = N - 1;
    while(left < N && right >= 0 && left < right) {
      int tmpSum = nums[left] + nums[right];
      int tmpAbs = abs(tmpSum - K);
      if(tmpAbs < minAbs) {
        minAbs = tmpAbs;
        cnt = 1;
      } else if (tmpAbs == minAbs)
        ++cnt; 

      if(tmpSum > K)
        --right;
      else 
        ++left;
    }
      cout << cnt << "\n";
  }
  return 0;
}