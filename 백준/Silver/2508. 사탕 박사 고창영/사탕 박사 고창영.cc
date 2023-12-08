#include <iostream>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int testCase;
    cin >> testCase;
    for(int tc = 0; tc < testCase; ++tc) {
        int W, H, candy = 0;
        cin >> H >> W;
        vector<char> v(W);
        vector<vector<char>> box(H, v);
        for(int h = 0; h < H; ++h) 
            for (int w = 0; w < W; ++w)
                cin >> box[h][w];

        for (int h = 0; h < H; ++h)
            for (int w = 0; w < W; ++w)
                if(box[h][w] == 'o') {
                    if(w - 1 >= 0 && w + 1 < W && box[h][w - 1] == '>' && box[h][w + 1] == '<')
                        ++candy;
                    else if(h - 1 >= 0 && h + 1 < H && box[h - 1][w] == 'v' && box[h + 1][w] == '^')
                        ++candy;
                }
        cout << candy << "\n";
    }
    return 0;
}