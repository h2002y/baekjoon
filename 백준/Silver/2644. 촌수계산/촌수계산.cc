#include <iostream>
#include <vector>
using namespace std;

int N, T1, T2, M;
vector<int> visited;
vector<vector<int>> graph;

void dfs(int curr, int cnt)
{
    for (int i = 0; i < graph[curr].size(); ++i)
    {
        int next = graph[curr][i];
        if (visited[next] == -1)
        {
            visited[next] = cnt;
            dfs(next, cnt + 1);
        }
    }
}

int main()
{
    cin >> N >> T1 >> T2 >> M;
    graph.resize(N + 1);
    visited.resize(N + 1, -1);
    for (int i = 0; i < M; ++i)
    {
        int left, right;
        cin >> left >> right;
        graph[left].push_back(right);
        graph[right].push_back(left);
    }
    visited[T1] = 0;
    dfs(T1, 1);
    cout << visited[T2] << "\n";
    return 0;
}