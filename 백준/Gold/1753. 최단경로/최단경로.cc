#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K, INF = 300000001;
vector<int> visited;
vector<vector<pair<int, int>>> graph;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second; // true == swap
    }
};

int main()
{
    cin >> V >> E >> K;
    graph.resize(V + 1);
    visited.resize(V + 1, INF);
    for (int i = 0; i < E; ++i)
    {
        int left, right, cost;
        cin >> left >> right >> cost;
        graph[left].push_back(make_pair(right, cost));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(K, 0));
    while (!pq.empty())
    {
        int curr = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if (visited[curr] <= cost)
            continue;
        visited[curr] = cost;
        for (int i = 0; i < graph[curr].size(); ++i)
        {
            int next = graph[curr][i].first;
            int nCost = cost + graph[curr][i].second;
            if (visited[next] > nCost)
                pq.push(make_pair(next, nCost));
        }
    }
    for (int i = 1; i <= V; ++i)
    {
        if (visited[i] == INF)
            cout << "INF\n";
        else
            cout << visited[i] << "\n";
    }
    return 0;
}