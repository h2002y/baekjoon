#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct coord {
    int y, x, cnt;
    coord(){}
    coord(int Y, int X, int Cnt) : y(Y), x(X), cnt(Cnt){}
}Coord;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        int I, sy, sx, ty, tx;
        cin >> I >> sx >> sy >> tx >> ty;
        vector<int> v(I, -1);
        vector<vector<int>> visited(I, v);
        queue<Coord> q;
        q.push(Coord(sy, sx, 0));
        while(!q.empty()) {
            Coord c = q.front();
            q.pop();
            if (visited[c.y][c.x] >= 0) continue;
            visited[c.y][c.x] = c.cnt;
            for (int i = 0; i < 8; ++i) {
                int ny = c.y + dy[i];
                int nx = c.x + dx[i];
                int nc = c.cnt + 1;
                if (0 <= ny && ny < I && 0 <= nx && nx < I && visited[ny][nx] == -1)
                    q.push(Coord(ny, nx, nc));
            }
        }
        cout << visited[ty][tx] << "\n";
    }
    return 0;
}