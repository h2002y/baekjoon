#include <iostream>
#include <vector>
using namespace std;

/** 해설
 *  비행 스케줄은 항상 연결 그래프를 이룬다.
 * => 스패닝 트리
 * 
 *  비행기를 타는 횟수가 아닌 비행기의 종류를 요구한다.
 * => 간선을 왕복(2번 탑승)해도 1개의 비행기로 취급
 * 
 * 따라서 답은 간선 개수인 N - 1
 */

int main () {
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N, M;
        cin >> N >> M;
        vector<pair<int, int>> planes(M);
        for (int i = 0; i < M; ++i)
            cin >> planes[i].first >> planes[i].second;
        cout << N - 1 << "\n";
    }
    return 0;
}