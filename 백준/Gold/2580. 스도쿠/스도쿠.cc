#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> coords;
int map [10];
int board [9][9];
bool isFound;

void recurse(int coordIdx) {
    if (isFound) return;
    if (coordIdx == coords.size()) {
        isFound = 1;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
    int y = coords[coordIdx].first;
    int x = coords[coordIdx].second;
    for (int i = 1; i <= 9; ++i) {
        // 이미 보드의 숫자가 9개면 x
        if (map[i] == 9) continue;

        // 같은 줄에 동일한 숫자가 있으면 x
        bool isExist = false;
        for (int j = 0; j < 9; ++j) {
            if (i == board[y][j] || i == board[j][x]) {
                isExist = true;
                break;
            }
        }
        if (isExist) continue;
         // 정사각형 탐색 0, 3, 6
        int dy = (y / 3) * 3;
        int dx = (x / 3) * 3;
        for (int ty = dy; ty < dy + 3; ++ty) {
            for (int tx = dx; tx < dx + 3; ++tx) {
                if (board[ty][tx] == i) {
                    isExist = true;
                    break;
                }
            }
        }
        if (isExist) continue;

        board[y][x] = i;
        map[i]++;
        recurse(coordIdx + 1);
        if(isFound) break;
        map[i]--;
        board[y][x] = 0;
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            map[board[i][j]]++;
            if (board[i][j] == 0)
                coords.push_back(make_pair(i, j));
        }
    }

    recurse(0);
    return 0;
}