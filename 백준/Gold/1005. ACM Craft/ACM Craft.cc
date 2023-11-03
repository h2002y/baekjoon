#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int testCase;
  cin >> testCase;
  for(int i = 0; i < testCase; i++) {
    int N, M;
    cin >> N >> M;
    vector<int> buildSec(N + 1), answer(N + 1), degree(N + 1), v;
    vector<vector<int>> graph(N + 1, v);
    for(int i = 1; i <= N; i++) {
      cin >> buildSec[i];
      answer[i] = buildSec[i];
    }
    for(int i = 0; i < M; i++) {
      int parent, child;
      cin >> parent >> child;
      graph[parent].push_back(child);
      degree[child]++;
    }

    int target;
    cin >> target;

    queue<int> q;
    for(int i = 1; i <= N; i++) 
      if(degree[i] == 0)
        q.push(i);
    
    while(!q.empty()) {
      int curr = q.front();
      q.pop();
      for(int next : graph[curr]) {
        degree[next]--;
        answer[next] = max(answer[next], answer[curr] + buildSec[next]);
        if(degree[next] == 0) q.push(next);
      }
    }
    cout << answer[target] << "\n";
  }
  return 0;
}