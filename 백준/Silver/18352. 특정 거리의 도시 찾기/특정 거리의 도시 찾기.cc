#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    int N, M, K, X, INF = 1000001;
    cin >> N >> M >> K >> X;
    vector<vector<int>> graph;
    vector<int> v;
    vector<int> visited(N + 1, INF);
    graph.resize(N + 1, v);
    for (int i = 0; i < M; ++i)
    {
        int left, right;
        cin >> left >> right;
        graph[left].push_back(right);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(X, 0));
    while (!pq.empty())
    {
        int curr = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if (cost >= visited[curr])
            continue;
        visited[curr] = cost;
        for (int i = 0; i < graph[curr].size(); ++i)
        {
            int next = graph[curr][i];
            int nCost = cost + 1;
            if (visited[next] > nCost)
                pq.push(make_pair(next, nCost));
        }
    }
    bool isPrinted = false;
    for (int i = 1; i <= N; ++i)
        if (visited[i] == K)
        {
            if (!isPrinted)
                isPrinted = true;
            cout << i << "\n";
        }
    if (!isPrinted)
        cout << "-1\n";
    return 0;
}