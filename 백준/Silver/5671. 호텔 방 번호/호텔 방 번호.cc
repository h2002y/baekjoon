#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    while (1)
    {
        cin >> N >> M;
        if (cin.eof())
            break;
        int cnt = 0;
        for (int i = N; i <= M; ++i)
        {
            vector<int> map(10);
            int tmp = i;
            bool isDup = false;
            while (tmp != 0)
            {
                map[tmp % 10]++;
                if (map[tmp % 10] > 1)
                {
                    isDup = true;
                    break;
                }
                tmp /= 10;
            }
            if (isDup)
                continue;
            else
                ++cnt;
        }
        cout << cnt << "\n";
    }
    return 0;
}