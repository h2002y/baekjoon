#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i <= t.size() - p.size(); ++i) {
        string curr = t.substr(i, p.size());
        if (curr <= p) ++answer;
    }
    return answer;
}