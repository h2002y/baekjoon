#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    int minY = wallpaper.size(), minX = wallpaper[0].size(), maxY = -1, maxX = -1;
    for (int i = 0; i < wallpaper.size(); ++i) {
        for (int j = 0; j < wallpaper[0].size(); ++j) {
            if (wallpaper[i][j] == '#') {
                if (i < minY) minY = i;
                if (j < minX) minX = j;
                if (i > maxY) maxY = i;
                if (j > maxX) maxX = j;
            }
        }
    }
    answer[0] = minY;
    answer[1] = minX;
    answer[2] = maxY + 1;
    answer[3] = maxX + 1;
    return answer;
}