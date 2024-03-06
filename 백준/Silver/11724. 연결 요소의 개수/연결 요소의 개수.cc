#include <iostream>
#include <vector>
using namespace std;

int N, M;

void dfs(int y, vector<vector<bool>>& graph, vector<bool>& visited){
    visited[y] = true;
    for(int i = 0; i < N; i++){
        if(graph[y][i] && !visited[i])
            dfs(i, graph, visited);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt = 0;
    cin>>N>>M;
    vector<vector<bool>> graph(N);
    vector<bool> v(N, false), visited(N, false);
    for(int i = 0; i < N; i++) graph[i] = v;
    for(int i = 0; i < M; i++){
        int x, y;
        cin>>x>>y;
        graph[x-1][y-1] = true;
        graph[y-1][x-1] = true;
    }
    for(int v = 0; v < N; v++)
        if(!visited[v]){
            dfs(v, graph, visited);
            cnt++;
        }
    cout<<cnt<<"\n";
    return 0;
}