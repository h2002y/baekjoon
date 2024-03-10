#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answer;

void extract(vector<vector<int>> data, int j, int target) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i][j] < target)
            answer.push_back(data[i]);
    }
}

void sortBy(int j){
    sort(answer.begin(), answer.end(), [j](vector<int> d1, vector<int> d2) {
        return d1[j] < d2[j];
    });
}

int getType(string input) {
    if (input == "code") return 0;
    else if (input == "date") return 1;
    else if (input == "maximum") return 2;
    else if (input == "remain") return 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    int j = getType(ext);
    extract(data, j, val_ext);
    j = getType(sort_by);
    sortBy(j);
    return answer;
}