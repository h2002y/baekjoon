#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer, alpha(26, 101);
    for (int i = 0; i < keymap.size(); ++i)
        for (int j = 0; j < keymap[i].length(); ++j) 
            if (alpha[keymap[i][j] - 'A'] > j + 1) 
                alpha[keymap[i][j] - 'A'] = j + 1;
    for (int i = 0; i < targets.size(); i++) {
        int clicks = 0;
        bool isExist = true;
        for (int j = 0; j < targets[i].length(); ++j) {
            int curr = alpha[targets[i][j] - 'A'];
            if (curr == 101) {
                answer.push_back(-1);
                isExist = false;
                break;
            }
            clicks += curr;
        }
        if (!isExist) continue;
        answer.push_back(clicks);
    }
    return answer;
}