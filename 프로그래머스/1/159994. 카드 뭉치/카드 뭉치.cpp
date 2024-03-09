#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int left = 0, right = 0, curr = 0;
    while (curr < goal.size()) {
        if (left < cards1.size() && cards1[left] == goal[curr]) {
            left++; curr++;
        } else if (right < cards2.size() && cards2[right] == goal[curr]) {
            right++; curr++;
        } else {
            answer = "No";
            break;
        }
    }
    return answer;
}