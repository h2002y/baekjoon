#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    int lastIdx = 0;
    for(int i = 0; i < my_string.length(); i++) {
        if(my_string[i] == ' ') {
            answer.push_back(my_string.substr(lastIdx, i - lastIdx));
            lastIdx = i + 1;
        } else if (i == my_string.length() - 1) {
            answer.push_back(my_string.substr(lastIdx));
        }
    }
    return answer;
}