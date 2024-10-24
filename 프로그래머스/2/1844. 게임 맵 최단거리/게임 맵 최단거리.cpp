#include<vector>
#include <queue>
using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

struct coord{
    int y;
    int x;
    int dist;
    coord(int Y, int X, int Dist) : y(Y), x(X), dist(Dist){};
};

int bfs(vector<vector<int>> maps) {
    int w = maps[0].size();
    int h = maps.size();
    vector<int> v(w, -1);
    vector<vector<int>> visited(h, v);
    
    visited[0][0] = 1;
    queue<coord> q;
    q.push(coord(0, 0, visited[0][0]));
    
    while(!q.empty()) {
        coord curr = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];
            int ndist = curr.dist + 1;
            if (0 <= ny && ny < h && 0 <= nx && nx < w && maps[ny][nx] && visited[ny][nx] == -1) {
                visited[ny][nx] = ndist;
                q.push(coord(ny, nx, ndist));
            }
        }
    }
    if (!visited[h - 1][w - 1]) return - 1;
    return visited[h - 1][w - 1];
}

int solution(vector<vector<int>> maps)
{
    return bfs(maps);
}