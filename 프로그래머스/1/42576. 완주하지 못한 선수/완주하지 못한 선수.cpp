#include <string>
#include <vector>
#include <map>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for (int i = 0; i < completion.size(); ++i) {
        m[completion[i]]++;
    }
    for (int i = 0; i < participant.size(); ++i) {    
        if (m.find(participant[i]) == m.end() || m[participant[i]] == 0) {
            answer = participant[i];
            break;
        } else {
            m[participant[i]]--;
        }
    }
    return answer;
}