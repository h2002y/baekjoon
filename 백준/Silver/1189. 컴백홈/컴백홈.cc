#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int N, M, K, answer;
vector<vector<char>> grid;
vector<vector<bool>> isVisited;

void dfs(int y, int x, int cnt, vector<vector<bool>> v)
{
    if (cnt > K)
        return;
    if (y == 0 && x == M - 1)
    {
        if (cnt == K)
            ++answer;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < N && 0 <= nx && nx < M && !v[ny][nx] && grid[ny][nx] != 'T')
        {
            v[ny][nx] = true;
            dfs(ny, nx, cnt + 1, v);
            v[ny][nx] = false;
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    vector<char> v1(M);
    vector<bool> v2(M);
    grid.resize(N, v1);
    isVisited.resize(N, v2);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    isVisited[N - 1][0] = true;
    dfs(N - 1, 0, 1, isVisited);
    cout << answer << "\n";
    return 0;
}