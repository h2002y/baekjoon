#include <iostream>
#include <vector>
using namespace std;

typedef struct cloud
{
    bool isAlive = true;
    int y, x;
    cloud(int Y, int X) : y(Y), x(X) {}
} Cloud;

vector<int> Md, Ms;
vector<cloud> clouds;
vector<vector<int>> grid;

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int N, M;

void cloudInit()
{
    clouds.push_back(Cloud(N, 1));
    clouds.push_back(Cloud(N, 2));
    clouds.push_back(Cloud(N - 1, 1));
    clouds.push_back(Cloud(N - 1, 2));
}

void move(int direction, int distance)
{
    for (int i = 0; i < clouds.size(); ++i)
    {
        clouds[i].y += (dy[direction] * distance) % N;
        if (clouds[i].y > N)
            clouds[i].y -= N;
        else if (clouds[i].y <= 0)
            clouds[i].y += N;

        clouds[i].x += (dx[direction] * distance) % N;
        if (clouds[i].x > N)
            clouds[i].x -= N;
        else if (clouds[i].x <= 0)
            clouds[i].x += N;
    }
}

void rain()
{
    for (int i = 0; i < clouds.size(); ++i)
    {
        Cloud c = clouds[i];
        grid[c.y][c.x]++;
    }
}

void disappear()
{
    for (int i = 0; i < clouds.size(); ++i)
    {
        clouds[i].isAlive = false;
    }
}

void copyWater()
{
    for (int i = 0; i < clouds.size(); ++i)
    {
        int totalBasket = 0;
        Cloud c = clouds[i];
        for (int j = 1; j <= 7; j += 2)
        {
            int ny = c.y + dy[j];
            int nx = c.x + dx[j];
            if (1 <= ny && ny <= N && 1 <= nx && nx <= N && grid[ny][nx] > 0)
                totalBasket++;
        }
        grid[c.y][c.x] += totalBasket;
    }
}

void makeCloud()
{
    int currClouds = clouds.size();
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            bool wasCloud = false;
            for (int c = 0; c < currClouds; ++c)
            {
                if (i == clouds[c].y && j == clouds[c].x)
                {
                    wasCloud = true;
                    break;
                }
            }
            if (wasCloud)
                continue;
            if (grid[i][j] >= 2)
            {
                grid[i][j] -= 2;
                clouds.push_back(Cloud(i, j));
            }
        }
    }
    clouds.erase(clouds.begin(), clouds.begin() + currClouds);
}

int main()
{
    cin >> N >> M;

    vector<int> v(N + 1);
    grid.resize(N + 1, v);
    Md.resize(M);
    Ms.resize(M);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> grid[i][j];

    for (int i = 0; i < M; ++i)
        cin >> Md[i] >> Ms[i];

    cloudInit();
    for (int i = 0; i < M; ++i)
    {
        move(Md[i] - 1, Ms[i]);
        rain();
        disappear();
        copyWater();
        makeCloud();
    }

    int totalWater = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            totalWater += grid[i][j];
    cout << totalWater << "\n";
    return 0;
}