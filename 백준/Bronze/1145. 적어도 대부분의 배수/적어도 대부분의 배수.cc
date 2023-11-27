#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int arr[5];
  int maxNum = 0;
  for(int i = 0; i < 5; i++)
    cin >> arr[i];
  int currNum = 4;
  while(true) {
    int cnt = 0;
    for(int i = 0; i < 5; i++)
      if(currNum % arr[i] == 0) cnt++;
    if(cnt >= 3) {
      cout << currNum << "\n";
      return 0;
    }
    ++currNum;
  }
  return 0;
}