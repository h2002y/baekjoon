#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  while (true) {
    int centimeter, numOfLego;
    cin >> centimeter;
    if (cin.eof() == true) return 0;
    cin >> numOfLego;
    centimeter *= 10000000;
    vector<int> lego(numOfLego);
    for (int i = 0; i < numOfLego; i++)
      cin >> lego[i];
    sort(lego.begin(), lego.end());
    int start = 0, end = numOfLego - 1;
    vector<pair<int, int>> answer;
    while (start < numOfLego && end >= 0 && start < end)
    {
      if ((lego[start] + lego[end]) == centimeter)
      {
        answer.push_back(make_pair(lego[start], lego[end]));
        ++start;
      }
      else if (lego[start] + lego[end] > centimeter)
        --end;
      else
        ++start;
    }

    if (answer.size() == 0)
      cout << "danger\n";
    else
    {
      int left = 0, right = 0, maxAbs = -1;
      for (int i = 0; i < answer.size(); i++)
      {
        int currAbs = abs(answer[i].first - answer[i].second);
        if (currAbs > maxAbs)
        {
          maxAbs = currAbs;
          left = answer[i].first;
          right = answer[i].second;
        }
      }
      cout << "yes " << left << " " << right << "\n";
    }
  }
  return 0;
}