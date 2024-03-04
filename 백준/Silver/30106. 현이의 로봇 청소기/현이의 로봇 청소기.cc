#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int N, M, K, cnt;
vector<vector<int>> height;
vector<vector<bool>> isCleaned;

void dfs(int y, int x)
{
    if (isCleaned[y][x])
        return;
    isCleaned[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < N && 0 <= nx && nx < M && !isCleaned[ny][nx] && abs(height[y][x] - height[ny][nx]) <= K)
            dfs(ny, nx);
    }
}

int main()
{
    cin >> N >> M >> K;
    vector<int> v1(M);
    vector<bool> v2(M);
    height.resize(N, v1);
    isCleaned.resize(N, v2);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> height[i][j];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (isCleaned[i][j])
                continue;
            dfs(i, j);
            ++cnt;
        }
    }
    cout << cnt << "\n";
    return 0;
}