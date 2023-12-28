#include <iostream>
#include <vector>
using namespace std;
int main () {
    vector<bool> v(100);
    vector<vector<bool>> paper(100, v);
    int N, answer = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        for (int w = x; w < x + 10; ++w) 
            for (int h = y; h < y + 10; ++h)
                if(!paper[h][w]) {
                    ++answer;
                    paper[h][w] = 1;
                }
    }
    cout << answer << "\n";
    return 0;
}