#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int H, W, maxHeight = 0, water = 0;
    cin >> H >> W;
    vector<int> blocks(W);
    for (int i = 0; i < W; ++i)
        cin >> blocks[i];
    for (int i = 1; i < W - 1; ++i) {
        int left = 0, right = 0, minWater;
        for (int l = 0; l < i; ++l)
            if(left < blocks[l]) left = blocks[l];
        for (int r = i + 1; r < W; ++r)
            if (right < blocks[r]) right = blocks[r];
        minWater = min(left, right);
        if(blocks[i] < minWater) water += minWater - blocks[i];
    }
    cout << water << "\n";
    return 0;
}