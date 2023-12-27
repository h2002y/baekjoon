#include <iostream>
#include <vector>
using namespace std;

typedef struct soldier {
    int Str;
    int Dex;
    int Int;
} Soldier;

int main() {
    int N, K, maxStr, maxDex, maxInt, minStat = 3000001;
    cin >> N >> K;
    vector<Soldier> soldiers(N);
    for (int i = 0; i < N; i++)
        cin >> soldiers[i].Str >> soldiers[i].Dex >> soldiers[i].Int;
    for (int s = 0; s < N; ++s) {
        for (int d = 0; d < N; ++d) {
            for (int i = 0; i < N; ++i) {
                int numOfWin = 0, tmpStr = soldiers[s].Str, tmpDex = soldiers[d].Dex, tmpInt = soldiers[i].Int;
                int tmpStat = tmpStr + tmpDex + tmpInt;
                for (int n = 0; n < N; ++n)
                    if(tmpStr >= soldiers[n].Str && tmpDex >= soldiers[n].Dex && tmpInt >= soldiers[n].Int)
                        ++numOfWin;
                if ( numOfWin >= K && tmpStat < minStat)
                    minStat = tmpStat;
            }
        }
    }
    cout << minStat << "\n";
    return 0;
}