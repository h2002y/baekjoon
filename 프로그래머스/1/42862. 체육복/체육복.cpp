#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n + 2, 1);
    students[0] = 0; students[n + 1] = 0;
    for (int i = 0; i < lost.size(); ++i)
        students[lost[i]]--;
    for (int i = 0; i < reserve.size(); ++i)
        students[reserve[i]]++;
    for (int i = 1; i <= n; ++i) {
        if (students[i] == 0) {
            int left = i - 1, right = i + 1;
            if (students[left] >= 2) {
                students[left]--;
                students[i]++;
            } else if (students[right] >= 2) {
                students[right]--;
                students[i]++;
            }
        }
        if (students[i] >= 1) ++answer;
    }
    return answer;
}