#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  int N, C;
  cin >> N >> C;
  vector<int> items(N);
  set<int> s;
  for(int i = 0; i < N; i++){
    cin >> items[i];
    s.insert(items[i]);
  }
  sort(items.begin(), items.end());

  if(s.count(C)) {
    cout << "1\n";
    return 0;
  }

  int left = 0, right = N - 1;
  while(left < N && right >= 0 && left < right) {
    if((C - items[left]) != items[left] && s.count(C - items[left])) {
      cout << "1\n";
      return 0;
    }
    if((C - (items[left] + items[right]) != items[left]) && (C - (items[left] + items[right]) != items[right]) && s.count(C - (items[left] + items[right]))) {
      cout << "1\n";
      return 0;
    }
    else if(items[left] + items[right] > C)
      --right;
    else 
      ++left;
  }
  cout << "0\n";

  return 0;
}