#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int currH = health;
    int sec = 0, bandaging = 0, attackP = 0;
    while (sec <= attacks[attacks.size() - 1][0]) {
        ++sec;
        if (sec < attacks[attackP][0]) {
            bandaging++;
            currH += bandage[1];
            if (bandaging == bandage[0]) {
                bandaging = 0;
                currH += bandage[2];
            }
            if (currH > health) currH = health;
        } else {
            bandaging = 0;
            currH -= attacks[attackP++][1];
            if (attackP >= attacks.size()) break;
            if (currH <= 0) break;
        }
    }
    if (currH <= 0) return -1;
    return currH;
}