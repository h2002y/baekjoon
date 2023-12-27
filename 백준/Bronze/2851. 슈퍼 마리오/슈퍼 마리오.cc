#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores(10);
    int sum = 0, tmpSum, minDiff, answer;
    for (int i = 0; i < 10; ++i) {
        cin >> scores[i];
        sum += scores[i];
    }
    minDiff = abs(sum - 100);
    answer = sum;
    tmpSum = sum;
    for(int i = 9; i >= 0; --i) {
        tmpSum -= scores[i];
        if(minDiff > abs(tmpSum - 100)) {
            minDiff = abs(tmpSum - 100);
            answer = tmpSum;
        } else break;
    }
    cout << answer << "\n";
    return 0;
}