#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int len = s.length();
    vector<int> answer(len);

    for (int right = 0; right < len; ++right) {
        bool isExist = false;
        for (int left = right - 1; left >= 0; --left) {
            if (s[right] == s[left]) {
                answer[right] = right - left;
                isExist = true;
                break;
            }
        }
        if (!isExist) answer[right] = -1;
    }
    return answer;
}