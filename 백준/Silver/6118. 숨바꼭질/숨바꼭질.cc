#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, minV, maxDist;
vector<int> dist, isVisited;
vector<vector<int>> graph;

int main()
{
    cin >> N >> M;
    graph.resize(N + 1);
    dist.resize(N + 1);
    isVisited.resize(N + 1, -1);
    minV = N + 1;
    for (int i = 0; i < M; ++i)
    {
        int left, right;
        cin >> left >> right;
        graph[left].push_back(right);
        graph[right].push_back(left);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    while (!q.empty())
    {
        int curr = q.front().first;
        int cDist = q.front().second;
        q.pop();
        if (isVisited[curr] != -1)
            continue;
        isVisited[curr] = cDist;
        dist[cDist]++;
        if (maxDist == cDist && minV > curr)
            minV = curr;
        else if (maxDist < cDist)
        {
            minV = curr;
            maxDist = cDist;
        }
        for (int i = 0; i < graph[curr].size(); ++i)
        {
            int next = graph[curr][i];
            int nDist = cDist + 1;
            if (isVisited[next] < nDist)
                q.push(make_pair(next, nDist));
        }
    }
    cout << minV << " " << maxDist << " " << dist[maxDist] << "\n";
    return 0;
}