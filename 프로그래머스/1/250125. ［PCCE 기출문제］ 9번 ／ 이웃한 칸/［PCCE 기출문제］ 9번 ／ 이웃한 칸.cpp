#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; ++i) {
        int ny = h + dy[i];
        int nx = w + dx[i];
        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size()) 
            continue;
        if (board[ny][nx] == board[h][w]) ++answer;
    }
    return answer;
}