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

int N, M, X, INF = 1000001;
vector<int> visitedP, visitedH;
vector<vector<pair<int, int>>> toParty, toHome;

void bfs(bool isHome)
{
    vector<int> visited;
    vector<vector<pair<int, int>>> graph;
    if (isHome)
    {
        visited = visitedH;
        graph = toHome;
    }
    else
    {
        visited = visitedP;
        graph = toParty;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(X, 0));
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
    if (isHome)
        visitedH = visited;
    else
        visitedP = visited;
}

int main()
{
    cin >> N >> M >> X;
    visitedP.resize(N + 1, INF);
    visitedH.resize(N + 1, INF);
    toParty.resize(N + 1);
    toHome.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int left, right, cost;
        cin >> left >> right >> cost;
        toParty[right].push_back(make_pair(left, cost));
        toHome[left].push_back(make_pair(right, cost));
    }
    bfs(0);
    bfs(1);
    int maxTime = 0;
    for (int i = 1; i <= N; ++i)
    {
        int sum = visitedH[i] + visitedP[i];
        if (sum > maxTime)
            maxTime = sum;
    }
    cout << maxTime << "\n";
    return 0;
}