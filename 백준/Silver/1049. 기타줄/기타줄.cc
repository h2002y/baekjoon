#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int N, M, minMoney = 100000000, minPackage = 1001, minSingle = 1001;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int package, single;
        cin >> package >> single;
        minPackage = min(minPackage, package);
        minSingle = min(minSingle, single);
    }
    // 패키지로만 살 때
    minMoney = min(minMoney, ((N / 6) + 1) * minPackage);
        
    // 패키지 + 낱개로 살 때
    minMoney = min(minMoney, ((N / 6) * minPackage) + ((N % 6) * minSingle));
        
    // 낱개로만 살 때
    minMoney = min(minMoney, N * minSingle);
    
    cout << minMoney << "\n";
    return 0;
}