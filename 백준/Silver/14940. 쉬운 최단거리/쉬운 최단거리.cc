#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

typedef struct coord
{
    int x, y, dist;
    coord(int X, int Y, int D) : x(X), y(Y), dist(D) {}
} Coord;

int main()
{
    int N, M, sy, sx;
    cin >> N >> M;
    vector<int> v(M, 0), v2(M, -2);
    vector<vector<int>> board(N, v), answer(N, v2);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                sy = i;
                sx = j;
            }
            else if (board[i][j] == 0)
                answer[i][j] = 0;
        }
    }
    queue<Coord> q;
    q.push(Coord(sx, sy, 0));
    while (!q.empty())
    {
        Coord curr = q.front();
        q.pop();
        if (answer[curr.y][curr.x] != -2)
            continue;
        answer[curr.y][curr.x] = curr.dist;
        for (int i = 0; i < 4; ++i)
        {
            int ny = dy[i] + curr.y;
            int nx = dx[i] + curr.x;
            int nd = curr.dist + 1;
            if (0 <= ny && ny < N && 0 <= nx && nx < M && answer[ny][nx] == -2)
            {
                q.push(Coord(nx, ny, nd));
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (answer[i][j] == -2)
                cout << -1 << " ";
            else
                cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}