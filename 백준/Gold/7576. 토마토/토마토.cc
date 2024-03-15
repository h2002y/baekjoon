#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int M, N;
int maxDay;

void ripen(vector<vector<int>>& box, vector<vector<int>>& visited){
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(box[i][j] == 1 && visited[i][j] == 0){
                q.push(make_pair(j , i));
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if((0 <= ny && ny < N)&&(0 <= nx && nx < M)&&(visited[ny][nx] == 0)&&(box[ny][nx] == 0)){
                q.push(make_pair(nx, ny));
                box[ny][nx] = 1;
                visited[ny][nx] = visited[y][x] + 1;
                if(maxDay < visited[ny][nx]) maxDay = visited[ny][nx];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>M>>N;
    vector<vector<int>> box(N), visited(N);
    vector<int> v(M, 0);
    for(int i = 0; i < N; i++){ // 벡터 초기화
        box[i] = v;
        visited[i] = v;
    }

    for(int i = 0; i < N; i++) // box 안 토마토 상태 입력
        for(int j = 0; j < M; j++)
            cin>>box[i][j];

    ripen(box, visited); // 토마토 익히기

    for(int i = 0; i < N; i++){ // 익지 않은 토마토 확인
        for(int j = 0; j < M; j++){
            if(box[i][j] == 0){
                cout<<-1<<"\n";
                return 0;
            }
        }
    }

    if(maxDay == 0) cout<<0<<"\n"; // 처음부터 전부 다 익은 토마토일 경우 0 출력
    else cout<<maxDay - 1<<"\n"; // 정답 출력
    return 0;
}