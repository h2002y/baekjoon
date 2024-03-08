#include <iostream>
using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    int left = 1, right = 1;
    long long sum = left;

    while (left <= N)
    {
        if (sum <= N)
        {
            if (sum == N)
                ++cnt;
            sum += ++right;
        }
        else
            sum -= left++;
    }

    cout << cnt << "\n";
    return 0;
}