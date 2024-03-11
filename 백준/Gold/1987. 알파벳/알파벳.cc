#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int R, C, maxCnt;
vector<bool> isExist(26);
vector<vector<char>> board;
vector<vector<bool>> isVisited;

void dfs(int y, int x, int cnt)
{
    if (cnt > maxCnt)
        maxCnt = cnt;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < R && 0 <= nx && nx < C && !isVisited[ny][nx] && !isExist[board[ny][nx] - 'A'])
        {
            isVisited[ny][nx] = true;
            isExist[board[ny][nx] - 'A'] = true;
            dfs(ny, nx, cnt + 1);
            isExist[board[ny][nx] - 'A'] = false;
            isVisited[ny][nx] = false;
        }
    }
}

int main()
{
    cin >> R >> C;
    vector<char> v(C);
    vector<bool> v2(C);
    board.resize(R, v);
    isVisited.resize(R, v2);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];
    isVisited[0][0] = true;
    isExist[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << maxCnt << "\n";
    return 0;
}