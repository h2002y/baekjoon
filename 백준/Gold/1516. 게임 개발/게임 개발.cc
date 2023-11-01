#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  vector<int> buildSec(N + 1), degree(N + 1), result(N + 1);
  vector<int> v;
  vector<vector<int>> graph(N + 1, v);
  for(int i = 1; i <= N; i++) {
    cin >> buildSec[i];
    while(true) {
      int parent;
      cin >> parent;
      if(parent == -1) break;
      graph[parent].push_back(i);
      degree[i]++;
    }
  }

  queue<int> q;
  for(int i = 1; i <= N; i++) {
    if(degree[i] == 0){
      q.push(i);
      result[i] = buildSec[i];
    }
  }
  
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(int i = 0; i < graph[curr].size(); i++) {
      int next = graph[curr][i];
      degree[next]--;
      result[next] = max(result[next], result[curr] + buildSec[next]);
      if(degree[next] == 0) q.push(next);
    }
  }

  for (int i = 1; i <= N; i++) 
    cout << result[i] << "\n";

  return 0;
}