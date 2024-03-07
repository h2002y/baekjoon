#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string, int> m;
    vector<int> answer;
    for (int i = 0; i < name.size(); ++i)
        m[name[i]] = yearning[i];
    for (int i = 0; i < photo.size(); ++i) {
        int sum = 0;
        for (int p = 0; p < photo[i].size(); ++p)
            sum += m[photo[i][p]];
        answer.push_back(sum);
    }
    return answer;
}