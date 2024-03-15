#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct coord
{
    int y, x, walls;

    coord() {}
    coord(int Y, int X, int Walls) : y(Y), x(X), walls(Walls) {}

    bool operator()(coord a, coord b)
    {
        return a.walls > b.walls;
    }
} Coord;

int N, M;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<vector<bool>> isWall;
vector<vector<int>> visited;

int main()
{
    cin >> N >> M;
    vector<bool> v1(N + 1);
    vector<int> v2(N + 1, (M + 1) * (N + 1));
    isWall.resize(M + 1, v1);
    visited.resize(M + 1, v2);
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
        {
            char input;
            cin >> input;
            if (input == '1')
                isWall[i][j] = true;
        }

    priority_queue<Coord, vector<Coord>, Coord> pq;
    pq.push(Coord(1, 1, 0));
    while (!pq.empty())
    {
        Coord c = pq.top();
        pq.pop();
        if (c.walls >= visited[c.y][c.x])
            continue;
        visited[c.y][c.x] = c.walls;
        for (int i = 0; i < 4; ++i)
        {
            int ny = c.y + dy[i];
            int nx = c.x + dx[i];
            int nw = c.walls;
            if (ny < 1 || ny > M || nx < 1 || nx > N)
                continue;
            if (isWall[ny][nx] && visited[ny][nx] > nw + 1)
                pq.push(Coord(ny, nx, nw + 1));
            else if (!isWall[ny][nx] && visited[ny][nx] > nw)
                pq.push(Coord(ny, nx, nw));
        }
    }
    cout << visited[M][N] << "\n";
    return 0;
}