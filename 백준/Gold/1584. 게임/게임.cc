#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct info
{
    int y;
    int x;
    int life;

    info(int Y, int X, int Life) : y(Y), x(X), life(Life) {}
} Info;

int N, M;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<vector<int>> danger, hp;

void bfs()
{
    queue<Info> q;
    q.push(Info(0, 0, 0));
    while (!q.empty())
    {
        Info curr = q.front();
        q.pop();
        if (hp[curr.y][curr.x] > curr.life)
            hp[curr.y][curr.x] = curr.life;
        else
            continue;
        for (int i = 0; i < 4; ++i)
        {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];
            if (0 <= ny && ny <= 500 && 0 <= nx && nx <= 500 && danger[ny][nx] != 2)
            {
                if (danger[ny][nx] == 1 && hp[ny][nx] > curr.life + 1)
                    q.push(Info(ny, nx, curr.life + 1));
                else if (danger[ny][nx] == 0 && hp[ny][nx] > curr.life)
                    q.push(Info(ny, nx, curr.life));
            }
        }
    }
    if (hp[500][500] == 30000)
        cout << "-1\n";
    else
        cout << hp[500][500] << "\n";
}

int main()
{
    vector<int> v(501), v2(501, 30000);
    danger.resize(501, v);
    hp.resize(501, v2);

    cin >> N;
    // 위험 구역 초기화
    for (int i = 0; i < N; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
        }
        if (y1 > y2)
        {
            int tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        for (int y = y1; y <= y2; ++y)
            for (int x = x1; x <= x2; ++x)
                if (danger[y][x] < 1)
                    danger[y][x] = 1;
    }

    cin >> M;
    // 죽음 구역 초기화
    for (int i = 0; i < M; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
        }
        if (y1 > y2)
        {
            int tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        for (int y = y1; y <= y2; ++y)
            for (int x = x1; x <= x2; ++x)
                if (danger[y][x] < 2)
                    danger[y][x] = 2;
    }

    bfs();
    return 0;
}