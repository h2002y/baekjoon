#include <iostream>
#include <queue>
using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int ,int> b) {
    return a.second > b.second;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int testCase;
  cin >> testCase;
  for(int tc = 0; tc < testCase; tc++){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v;
    vector<vector<pair<int ,int>>> graph(N + 1, v);
    for(int i = 0; i < M; i++) {
      int left, right, cost;
      cin >> left >> right >> cost;
      graph[left].push_back(make_pair(right, cost));
      graph[right].push_back(make_pair(left, cost));
    }
    int K;
    cin >> K;
    vector<int> friends(K);
    for(int i = 0; i < K; i++)
      cin >> friends[i];
    int minDist = 2000000000;
    int room = 0;
    for(int i = 1; i <= N; i++){
      vector<int> visited(N + 1, 2000000000);
      priority_queue<pair<int ,int>, vector<pair<int, int>>, cmp> pq;
      visited[i] = 0;
      pq.push(make_pair(i, 0));
      while(!pq.empty()) {
        int curr = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(visited[curr] < cost) continue;
        for(int j = 0; j < graph[curr].size(); j++) {
          int next = graph[curr][j].first;
          int nextCost = graph[curr][j].second + cost;
          if(visited[next] > nextCost) {
            visited[next] = nextCost;
            pq.push(make_pair(next, nextCost)); 
          }
        }
      }

      int distSum = 0;
      for(int j = 0; j < K; j++) 
        distSum += visited[friends[j]];

      if(distSum < minDist) {
        minDist = distSum;
        room = i;
      }
    }
    cout << room << "\n";
  }
  return 0;
}