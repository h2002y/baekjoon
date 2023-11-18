#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int lastMissile = -1;
    sort(targets.begin(), targets.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });
    for(vector<int> target : targets) {
        if(lastMissile == -1) {
            lastMissile = target[1];
            ++answer;
        }
        if(target[0] < lastMissile && lastMissile <= target[1]) continue;
        lastMissile = target[1];
        ++answer;
    }
    return answer;
}