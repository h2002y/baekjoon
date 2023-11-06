#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  while(true) {
    int N, M;
    cin >> N >> M;
    if(N == 0 && M == 0) break;
    vector<int> v, degree(N + 1), answer;
    vector<vector<int>> graph(N + 1, v);

    for(int i = 0; i < M; i++) {
      int parent, child;
      cin >> parent >> child;
      graph[parent].push_back(child);
      ++degree[child];
    }

    queue<int> q;

    int numOfParent = 0;
    for(int i = 1; i <= N; i++) {
      if(degree[i] == 0){
        q.push(i);
        ++numOfParent;
      } 
    }

    if(numOfParent == 0) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
      
    while(!q.empty()) {
      int curr = q.front();
      q.pop();
      answer.push_back(curr);
      for(int next : graph[curr]) {
        --degree[next];
        if(degree[next] == 0)
          q.push(next);
      }
    }

    if(answer.size() != N) {
      cout << "IMPOSSIBLE\n";
    } else {
      for (int i : answer)
        cout << i << "\n";
    }
  }
  return 0;
}