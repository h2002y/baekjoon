#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int N, maxCandy;
vector<vector<char>> board;

void check()
{
    // 가로 탐색
    for (int i = 0; i < N; ++i)
    {
        int currC = 1, maxC = 0;
        char prev = board[i][0];
        for (int j = 1; j < N; ++j)
        {
            if (board[i][j] == prev)
            {
                ++currC;
                if (currC > maxC)
                    maxC = currC;
            }
            else
            {
                currC = 1;
                prev = board[i][j];
            }
        }
        if (maxC > maxCandy)
            maxCandy = maxC;
    }

    // 세로 탐색
    for (int j = 0; j < N; ++j)
    {
        int currC = 1, maxC = 0;
        char prev = board[0][j];
        for (int i = 1; i < N; ++i)
        {
            if (board[i][j] == prev)
            {
                ++currC;
                if (currC > maxC)
                    maxC = currC;
            }
            else
            {
                currC = 1;
                prev = board[i][j];
            }
        }
        if (maxC > maxCandy)
            maxCandy = maxC;
    }
}

int main()
{
    cin >> N;
    vector<char> v(N);
    board.resize(N, v);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int n = 0; n < 4; ++n)
            {
                int ny = i + dy[n];
                int nx = j + dx[n];
                if (0 <= ny && ny < N && 0 <= nx && nx < N && board[i][j] != board[ny][nx])
                {
                    char tmp = board[i][j];
                    board[i][j] = board[ny][nx];
                    board[ny][nx] = tmp;
                    check();
                    board[ny][nx] = board[i][j];
                    board[i][j] = tmp;
                }
            }
    cout << maxCandy << "\n";
    return 0;
}