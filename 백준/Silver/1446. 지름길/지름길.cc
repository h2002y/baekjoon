#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, D, INF = 1200001;
vector<int> visited;
vector<bool> isExist;
vector<vector<pair<int, int>>> graph;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    cin >> N >> D;
    vector<pair<int, int>> v;
    graph.resize(10001, v);
    visited.resize(10001, INF);
    isExist.resize(10001);

    for (int i = 0; i < N; ++i)
    {
        int left, right, cost;
        cin >> left >> right >> cost;
        isExist[left] = true;
        graph[left].push_back(make_pair(right, cost));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty())
    {
        int curr = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if (visited[curr] > cost)
            visited[curr] = cost;
        if (isExist[curr])
        {
            for (int i = 0; i < graph[curr].size(); ++i)
            {
                int next = graph[curr][i].first;
                int nCost = cost + graph[curr][i].second;
                if (next <= D && visited[next] > nCost)
                    pq.push(make_pair(next, nCost));
            }
        }
        if (curr < D && visited[curr + 1] > cost + 1)
            pq.push(make_pair(curr + 1, cost + 1));
    }
    cout << visited[D] << "\n";
    return 0;
}