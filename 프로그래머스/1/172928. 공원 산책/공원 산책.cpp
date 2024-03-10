#include <string>
#include <vector>

using namespace std;
          // E0 W1 S2 N3 
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int currY, currX;
    for (int i = 0; i < park.size(); ++i)
        for (int j = 0; j < park[i].size(); ++j)
            if (park[i][j] == 'S') {
                currY = i;
                currX = j;
            }
    for (int i = 0; i < routes.size(); ++i) {
        int dir, dis;
        if(routes[i][0] == 'E') dir = 0;
        else if (routes[i][0] == 'W') dir = 1;
        else if (routes[i][0] == 'S') dir = 2;
        else if (routes[i][0] == 'N') dir = 3;
        dis = routes[i][2] - '0';
        int ny = currY + (dy[dir] * dis);
        int nx = currX + (dx[dir] * dis);
        if (ny < 0 || ny >= park.size() || nx < 0 || nx >= park[0].size())
            continue;
        bool isBlocked = false;
        for (int j = 1; j <= dis; ++j) {
            if (park[currY + dy[dir] * j][currX + dx[dir] * j] == 'X') {
                isBlocked = true;
                break;
            }
        }
        if (isBlocked) continue;
        currY = ny;
        currX = nx;
    }
    answer.push_back(currY);
    answer.push_back(currX);
    return answer;
}