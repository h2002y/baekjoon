#include <string>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> conn;

void dfs(int curr) {
    visited[curr] = true;
    for (int i = 0; i < visited.size(); ++i) {
        if (visited[i] || i == curr) continue;
        if (conn[curr][i]) dfs(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    conn = computers;
    visited.resize(n);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            answer++;
            dfs(i);
        }
    }
    return answer;
}