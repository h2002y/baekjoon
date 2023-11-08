#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
  bool operator() (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

const long long INF = 5000000000;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, M;
  cin >> N;
  vector<int> friends;
  vector<long long> v1(N + 1, INF);
  vector<pair<int, int>> v2;
  vector<vector<pair<int, int>>> graph(N + 1, v2);
  vector<vector<long long>> answer(3, v1);
  for(int i = 0; i < 3; i++) {
    int f;
    cin >> f;
    friends.push_back(f);
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    int left, right, cost;
    cin >> left >> right >> cost;
    graph[left].push_back(make_pair(right, cost));
    graph[right].push_back(make_pair(left, cost));
  }

  for(int f = 0; f < 3; f++) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    answer[f][friends[f]] = 0;
    pq.push(make_pair(friends[f], 0));

    while(!pq.empty()) {
      int curr = pq.top().first;
      int dist = pq.top().second;
      pq.pop();
      if(answer[f][curr] < dist) continue;
      for(pair<int, int> next : graph[curr]) {
        int nextF = next.first;
        int nextDist = dist + next.second;
        if(nextDist < answer[f][nextF]) {
          answer[f][nextF] = nextDist;
          pq.push(make_pair(nextF, nextDist));
        }
      }
    }
  }
  int maxV = 0;
  long long maxE = 0;
  for(int i = 1; i <= N; i++) {
    long long tmpE = min(answer[0][i], answer[1][i]);
    tmpE = min(answer[2][i], tmpE);
    if(tmpE >= maxE) {
      maxE = tmpE;
      maxV = i;
    }
  }
  cout << maxV << "\n";
  return 0;
}