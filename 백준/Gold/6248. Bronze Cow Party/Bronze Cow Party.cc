#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000000;

struct cmp{
  bool operator()(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
  }
};

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> visited(N + 1, INF);
  vector<pair<int, int>> tmp;
  vector<vector<pair<int, int>>> graph(N + 1, tmp);
  for(int i = 0; i < M; i++){
    int left, right, cost;
    cin >> left >> right >> cost;
    graph[left].push_back(make_pair(right, cost));
    graph[right].push_back(make_pair(left, cost));
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push(make_pair(X, 0));
  while(!pq.empty()){
    int curr = pq.top().first;
    int cost = pq.top().second;
    pq.pop();
    if(cost >= visited[curr]) continue;
    visited[curr] = cost;
    for(int i = 0; i < graph[curr].size(); i++){
      int next = graph[curr][i].first;
      int nextCost = graph[curr][i].second + cost;
      if(visited[next] > nextCost){
        pq.push(make_pair(next, nextCost));
      }
    }
  }

  int maxSec = 0;
  for(int i = 1; i <= N; i++)
    if(visited[i] > maxSec)
      maxSec = visited[i];

  cout << maxSec * 2 << "\n";

  return 0;
}