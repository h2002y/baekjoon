#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int H, W, answer;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<vector<bool>> island;

typedef struct coord
{
    int y, x, time;
    coord(int Y, int X, int Time) : y(Y), x(X), time(Time) {}
} Coord;

int bfs(int y, int x)
{
    vector<bool> v2(W);
    vector<vector<bool>> isVisited(H, v2);
    queue<Coord> q;
    q.push(Coord(y, x, 0));
    int maxTime = 0;
    while (!q.empty())
    {
        Coord c = q.front();
        q.pop();
        if (isVisited[c.y][c.x])
            continue;
        isVisited[c.y][c.x] = true;
        if (maxTime < c.time)
            maxTime = c.time;
        for (int i = 0; i < 4; ++i)
        {
            int ny = c.y + dy[i];
            int nx = c.x + dx[i];
            int nTime = c.time + 1;
            if (0 <= ny && ny < H && 0 <= nx && nx < W && island[ny][nx] && !isVisited[ny][nx])
                q.push(Coord(ny, nx, nTime));
        }
    }
    return maxTime;
}

int main()
{
    cin >> H >> W;
    vector<bool> v(W);
    island.resize(H, v);
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            char input;
            cin >> input;
            if (input == 'W')
                continue;
            else if (input == 'L')
                island[i][j] = true;
        }
    }
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (!island[i][j])
                continue;
            int dist = bfs(i, j);
            if (answer < dist)
                answer = dist;
        }
    }
    cout << answer << "\n";
    return 0;
}