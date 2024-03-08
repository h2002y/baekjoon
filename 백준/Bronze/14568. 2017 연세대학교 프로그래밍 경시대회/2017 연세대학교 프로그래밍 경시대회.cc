#include <iostream>
using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    for (int i = 1; i < N - 1; ++i)
    {
        for (int j = i + 2; j < N - i - 1; ++j)
        {
            int z = N - i - j;
            if (z % 2 == 0)
                ++cnt;
        }
    }
    cout << cnt << "\n";
    return 0;
}