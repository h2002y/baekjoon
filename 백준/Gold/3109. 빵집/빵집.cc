#include <iostream>
#include <vector>
using namespace std;

int R, C, maxPipes;
vector<bool> isCompleted;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int dy[3] = {-1, 0, 1};
int dx = 1;

void checkLine(int y, int x, int start)
{
    if (isCompleted[start])
        return;
    if (x == C - 1)
    {
        isCompleted[start] = true;
        ++maxPipes;
        return;
    }
    for (int i = 0; i < 3; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx;
        if (0 <= ny && ny < R && 0 <= nx && nx < C && !visited[ny][nx] && grid[ny][nx] != 'x' && !isCompleted[start])
        {
            visited[ny][nx] = true;
            checkLine(ny, nx, start);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    vector<char> v1(C);
    vector<bool> v2(C);
    grid.resize(R, v1);
    visited.resize(R, v2);
    isCompleted.resize(R);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> grid[i][j];
    for (int i = 0; i < R; ++i)
    {
        visited[i][0] = true;
        checkLine(i, 0, i);
    }
    cout << maxPipes << "\n";
    return 0;
}