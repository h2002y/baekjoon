#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1000000000;

typedef struct road {
  int curr;
  int cost;
  int seq;
  bool operator()(road a, road b){
    return a.cost > b.cost;
  }
  road(){}
  road(int Curr, int Cost, int Seq) : curr(Curr), cost(Cost), seq(Seq) {}
}Road;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, M, A, B, C;
  cin >> N >> M >> A >> B >> C;
  vector<pair<int, int>> v;
  vector<vector<pair<int, int>>> graph(N + 1, v);
  for(int i = 0; i < M; i++){
    int left, right, cost;
    cin >> left >> right >> cost;
    graph[left].push_back(make_pair(right, cost));
    graph[right].push_back(make_pair(left, cost));
  }
  vector<int> answer(N + 1, INF);
  vector<int> sequence(N + 1, 0);
  priority_queue<Road, vector<Road>, Road> pq;
  pq.push(Road(A, 0, 1));
  while(!pq.empty()){
    Road road = pq.top();
    pq.pop();
    if(answer[road.curr] < road.cost) continue;
    answer[road.curr] = road.cost;
    sequence[road.seq] = road.curr;
    for(int i = 0; i < graph[road.curr].size(); i++){
      int next = graph[road.curr][i].first;
      int nextCost = graph[road.curr][i].second + road.cost;
      if(answer[next] > nextCost){
        answer[next] = nextCost;
        pq.push(Road(next, nextCost, road.seq + 1));
      }
    }
  }
  if(answer[B] > C){
    cout << -1 << "\n";
    return 0;
  }
  int maxCost = 0;
  int prev = 0;
  for(int i = 1; i <= N; i++){
    if(sequence[i] == 0) break;
    maxCost = max(maxCost, answer[sequence[i]] - prev);
    prev = answer[sequence[i]];
  }
  cout << maxCost << "\n";
  return 0;
}