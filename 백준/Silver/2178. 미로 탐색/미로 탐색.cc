#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int N, M;
void bfs(vector<string> &map, queue<pair<int, int>> &q, vector<vector <int>> &distance, int x, int y){
    q.push(make_pair(x, y));
    distance[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if((0 <= nx && nx < N) && (0 <= ny && ny < M) && distance[nx][ny] == 0 && map[nx][ny] == '1'){ 
                q.push(make_pair(nx, ny));
                distance[nx][ny] = distance[x][y] + 1;
            }
        }
    }
}

int main(){
    cin>>N>>M;
    vector<string> map(N);
    vector<int> v(M);
    vector<vector <int>> distance(N, v);
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++) cin>>map[i];
    bfs(map, q, distance, 0, 0);//좌표값 0,0
    cout<<distance[N-1][M-1];
    return 0;
}