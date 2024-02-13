#include <iostream>
#include <vector>
using namespace std;

int G, S, minGuitar, maxSong;
vector<string> guitars;

void recurse(int idx, int cnt, vector<bool> isAvailSong) {
    if (cnt > 0) {
        int song = 0;
        for (int i = 0; i < S; i++)
            if (isAvailSong[i]) ++song;
        if (song > maxSong) {
            maxSong = song;
            minGuitar = cnt;
        } else if (song == maxSong) {
            if (cnt < minGuitar) minGuitar = cnt;
        }
    }
    if (idx == G) return;
    recurse(idx + 1, cnt, isAvailSong);
    for (int i = 0; i < S; ++i)
        if (guitars[idx][i] == 'Y')
            isAvailSong[i] = true;
    recurse(idx + 1, cnt + 1, isAvailSong);
}

int main () {
    cin >> G >> S;
    minGuitar = G + 1;
    guitars.resize(G);
    vector<bool> isAvail(S);
    string guitar;
    for (int i = 0; i < G; ++i)
        cin >> guitar >> guitars[i];
    recurse(0, 0, isAvail);
    if (maxSong == 0) cout << "-1\n";
    else cout << minGuitar << "\n";
    return 0;
}