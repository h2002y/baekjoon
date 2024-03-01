#include <iostream>
#include <vector>
using namespace std;

typedef struct cleaner
{
    int y, x;
    int direction;
    bool isOn = true;
} Cleaner;

Cleaner robot;

int N, M, maxCleaned;
vector<vector<int>> room;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void cleanCurrent()
{
    if (room[robot.y][robot.x] == 0)
    {
        room[robot.y][robot.x] = -1;
        maxCleaned++;
    }
}

bool checkAround()
{
    for (int i = 0; i < 4; i++)
    {
        int ny = robot.y + dy[i];
        int nx = robot.x + dx[i];
        if (0 <= ny && ny < N && 0 <= nx && nx < M && room[ny][nx] == 0)
            return true;
    }
    return false;
}

void goReverse()
{
    int ny = robot.y + (dy[robot.direction] * -1);
    int nx = robot.x + (dx[robot.direction] * -1);
    if (0 <= ny && ny < N && 0 <= nx && nx < M && room[ny][nx] != 1)
    {
        robot.y = ny;
        robot.x = nx;
    }
    else
        robot.isOn = false;
}

void moveAround()
{
    robot.direction--;
    if (robot.direction == -1)
        robot.direction = 3;
    int ny = robot.y + dy[robot.direction];
    int nx = robot.x + dx[robot.direction];
    if (0 <= ny && ny < N && 0 <= nx && nx < M && room[ny][nx] == 0)
    {
        robot.y = ny;
        robot.x = nx;
    }
}

int main()
{
    cin >> N >> M >> robot.y >> robot.x >> robot.direction;
    vector<int> v(M);
    room.resize(N, v);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> room[i][j];
    while (robot.isOn)
    {
        cleanCurrent();
        if (checkAround())
            moveAround();
        else
            goReverse();
    }
    cout << maxCleaned << "\n";
    return 0;
}