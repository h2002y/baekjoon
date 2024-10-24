#include <string>
#include <vector>
using namespace std;

vector<int> arr;
int t, answer = 0;

void dfs(int sum, int cnt) {
    if (cnt == arr.size()) {
        if (sum == t) answer++;
        return;
    }
    dfs(sum + arr[cnt], cnt + 1);
    dfs(sum - arr[cnt], cnt + 1);
}

int solution(vector<int> numbers, int target) {
    arr = numbers;
    t = target;
    dfs(0, 0);
    return answer;
}