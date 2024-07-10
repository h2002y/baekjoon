#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Turn {
    int sec;
    char dir;
    Turn(int Sec, char Dir) : sec(Sec), dir(Dir){}
};

struct Coord {
    int y, x;
    Coord(int Y, int X) : y(Y), x(X){}
};

struct Worm {
    int headY, headX, tailY, tailX, currSec, turnIdx, currDir;
    Worm(int HY, int HX, int TY, int TX, int CS, int TI, int CD) : headY(HY), headX(HX), tailY(TY), tailX(TX), currSec(CS), turnIdx(TI), currDir(CD){}
};

int N;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
bool isGameOver;
queue<Coord> q;
vector<Turn> turns;
vector<vector<int>> board;
Worm worm(1, 1, 1, 1, 0, 0, 0);

bool cmp(Turn a, Turn b) {
    return a.sec < b.sec;
}

// 방향 전환
void checkTurn() {
    if (worm.currSec == turns[worm.turnIdx].sec) {
        if (turns[worm.turnIdx].dir == 'L') {
            worm.currDir--;
            if (worm.currDir < 0) worm.currDir = 3;
        } else if (turns[worm.turnIdx].dir == 'D') {
            worm.currDir++;
            if (worm.currDir > 3) worm.currDir = 0;
        }
        worm.turnIdx++;
    }
}

void move() {
    int ny = worm.headY + dy[worm.currDir];
    int nx = worm.headX + dx[worm.currDir];

    // 게임 종료 확인
    if (ny < 1 || ny > N || nx < 1 || nx > N || board[ny][nx] == -1) {
        isGameOver = true;
        return;
    }

    // 지렁이 머리 늘리기
    worm.headY = ny;
    worm.headX = nx;
    q.push(Coord(ny, nx));
    
    if (board[ny][nx] == 0) {
        board[worm.tailY][worm.tailX] = 0;
        q.pop();

        // 꼬리의 위치 갱신
        Coord curr = q.front();
        worm.tailY = curr.y;
        worm.tailX = curr.x;
    }
    board[ny][nx] = -1;
    worm.currSec++;
}

int main () {
    cin >> N;
    vector<int> v(N + 1);
    board.resize(N + 1, v);
    int apples;
    cin >> apples;

    // 사과 위치 입력
    for (int i = 0; i < apples; ++i) {
        int y, x;
        cin >> y >> x;
        board[y][x] = 1;
    }

    board[1][1] = -1;
    q.push(Coord(1, 1));

    // 방향 전환 입력 및 오름차순 정렬
    int L;
    cin >> L;
    for (int i = 0; i < L; ++i) {
        int sec;
        char dir;
        cin >> sec >> dir;
        turns.push_back(Turn(sec, dir));
    }
    sort(turns.begin(), turns.end(), cmp);

    while(!isGameOver) {
        move();
        checkTurn();
    }

    cout << worm.currSec + 1 << "\n";

    return 0;
}