#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        int N, M, cnt = 0;
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        vector<int> C1(N), C2(M);
        for (int i = 0; i < N; ++i)
            cin >> C1[i];
        for (int i = 0; i < M; ++i)
            cin >> C2[i];
        int c1 = 0, c2 = 0;
        while (c1 < N && c2 < M)
        {
            if (C1[c1] == C2[c2])
            {
                ++cnt;
                ++c1;
                ++c2;
            }
            while (c1 < N && C1[c1] < C2[c2])
                ++c1;
            while (c2 < M && C2[c2] < C1[c1])
                ++c2;
        }
        cout << cnt << "\n";
    }
    return 0;
}