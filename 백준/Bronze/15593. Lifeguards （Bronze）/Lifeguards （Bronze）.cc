#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(2), timeline(1001);
    vector<vector<int>> cows(N, v);
    for(int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1];
        for(int j = cows[i][0]; j < cows[i][1]; j++)
            ++timeline[j];
    }

    int sumTime = 0, maxTime = 0;
    for(int i = 0; i < 1001; i++)
        if(timeline[i] > 0) sumTime++;
    for(int i = 0; i < N; i++) {
        int tmpTime = sumTime;
        for(int j = cows[i][0]; j < cows[i][1]; j++) 
            if(timeline[j] - 1 <= 0)
                --tmpTime;
        if(maxTime < tmpTime)
            maxTime = tmpTime;
    }
    cout << maxTime << "\n";
    return 0;
}