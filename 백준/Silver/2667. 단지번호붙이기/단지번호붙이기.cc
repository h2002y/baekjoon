#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25];
int N;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int y, int x, int currNo, int *sum){
    map[y][x] += currNo;
    (*sum)++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((0 <= nx && nx < N) && (0 <= ny && ny < N) && map[ny][nx] && map[ny][nx] == 1)
            dfs(ny, nx, currNo, sum);
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    vector<int> result;
    int currNo;
    for(int i = 0; i < N; i++){
        string s;
        cin>>s;
        for(int j = 0; j < N; j++)
            if(s[j] == '1') map[i][j] = 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1){
                int total = 0;
                dfs(i, j, currNo, &total);
                result.push_back(total);
                currNo++;
            }
        }
    }
    sort(result.begin(), result.end());
    cout<<result.size()<<"\n";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<"\n";
    return 0;
}