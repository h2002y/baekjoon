#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Coord{
    int x, y;
    Coord(int Y, int X) : y(Y), x(X) {}
};

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int N, M, maxSafeArea = 0;
vector<Coord> virus;

void getSafeArea(vector<vector<int>> area) {
    queue<Coord> q;
    for (int i = 0; i < virus.size(); ++i) 
        q.push(virus[i]);
    while (!q.empty()) {
        Coord curr = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < M && area[ny][nx] == 0) {
                area[ny][nx] = 2;
                q.push(Coord(ny, nx));
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (area[i][j] == 0)
                ++sum;
    if (sum > maxSafeArea) maxSafeArea = sum;
}

void recurse(vector<vector<int>> tmp, int degree) {
    if (degree >= 3) {
        getSafeArea(tmp);
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(tmp[i][j] == 0) {
                tmp[i][j] = 1;
                recurse(tmp, degree + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> v(M);
    vector<vector<int>> RI(N, v);

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j) {
            cin >> RI[i][j];
            if (RI[i][j] == 2)
                virus.push_back(Coord(i, j));
        }
    }

    recurse(RI, 0);

    cout << maxSafeArea << "\n";

    return 0;
}