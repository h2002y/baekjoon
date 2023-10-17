#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
  }
};

int main(){
  int N, P, C;
  cin >> N >> P >> C;
  vector<int> cows(N);
  for(int i = 0; i < N; i++)
    cin >> cows[i];

  vector<pair<int, int>> v;
  vector<vector<pair<int, int>>> graph(P + 1, v);
  vector<int> v2(P + 1, 2000000000);
  vector<vector<int>> result(N, v2);

  for(int i = 0; i < C; i++){
    int left, right, cost;
    cin >> left >> right >> cost;
    graph[left].push_back(make_pair(right, cost));
    graph[right].push_back(make_pair(left, cost));
  }
  for(int i = 0; i < N; i++){
    int cow = cows[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(cow, 0));
    result[i][cow] = 0;
    while(!pq.empty()){
      int curr = pq.top().first;
      int cost = pq.top().second;
      pq.pop();
      if(result[i][curr] < cost) continue;
      for(int j = 0; j < graph[curr].size(); j++){
        int next = graph[curr][j].first;
        int nextCost = graph[curr][j].second + cost;
        if(result[i][next] > nextCost){
          pq.push(make_pair(next, nextCost));
          result[i][next] = nextCost;
        }
      }
    }
  }

  int minCost = 2000000000;
  for(int j = 1; j <= P; j++){
    int sum = 0;
    for(int i = 0; i < N; i++)
      sum += result[i][j];
    minCost = min(minCost, sum);
  }
  cout << minCost << "\n";
  return 0;
}