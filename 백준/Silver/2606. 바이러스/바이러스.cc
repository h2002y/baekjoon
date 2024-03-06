#include <iostream>
#include <vector>
using namespace std;

int N, M, maxComputer;
vector<bool> isVisited;
vector<vector<int>> graph;

void dfs(int curr)
{
    for (int i = 0; i < graph[curr].size(); ++i)
    {
        int next = graph[curr][i];
        if (!isVisited[next])
        {
            maxComputer++;
            isVisited[next] = true;
            dfs(next);
        }
    }
}

int main()
{
    cin >> N >> M;
    isVisited.resize(N + 1);
    graph.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int left, right;
        cin >> left >> right;
        graph[left].push_back(right);
        graph[right].push_back(left);
    }
    isVisited[1] = true;
    dfs(1);
    cout << maxComputer << "\n";
    return 0;
}