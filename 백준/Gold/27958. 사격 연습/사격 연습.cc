#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int N, K, maxScore;
vector<int> bullets;
vector<vector<int>> board;

void recur(int cnt, int score, vector<vector<int>> full, vector<vector<int>> curr)
{
    if (cnt == K)
    {
        if (score > maxScore)
            maxScore = score;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        vector<vector<int>> tmp = curr, fullHp = full;
        int sum = 0;
        for (int j = 0; j < N; ++j)
        {
            if (tmp[i][j] == 0)
                continue;
            else if (tmp[i][j] >= 10)
            {
                sum += tmp[i][j];
                tmp[i][j] = 0;
                fullHp[i][j] = 0;
                break;
            }
            else
            {
                tmp[i][j] -= bullets[cnt];
                if (tmp[i][j] <= 0)
                {
                    sum += fullHp[i][j];
                    int nextTarget = fullHp[i][j] / 4;
                    fullHp[i][j] = 0;
                    tmp[i][j] = 0;
                    for (int k = 0; k < 4; ++k)
                    {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (0 <= ny && ny < N && 0 <= nx && nx < N && fullHp[ny][nx] == 0)
                            tmp[ny][nx] = fullHp[ny][nx] = nextTarget;
                    }
                }
                break;
            }
        }
        recur(cnt + 1, score + sum, fullHp, tmp);
    }
}

int main()
{
    cin >> N >> K;
    vector<int> v(N);
    board.resize(N, v);
    bullets.resize(K);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    for (int i = 0; i < K; ++i)
        cin >> bullets[i];
    recur(0, 0, board, board);
    cout << maxScore << "\n";
    return 0;
}