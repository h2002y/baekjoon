#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int team = 0;
    while(true) {
        int girl = (team + 1) * 2, boy = team + 1;
        if(girl <= N && boy <= M && girl + boy + K <= N + M)
            ++team;
        else break;
    }
    cout << team << "\n";
    return 0;
}