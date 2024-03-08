#include <iostream>
using namespace std;

int main()
{
    int sum = 0, minDiff = 1000, maxSum = 0;
    int mush[10];
    for (int i = 0; i < 10; ++i)
    {
        cin >> mush[i];
        sum += mush[i];

        if (minDiff == abs(sum - 100) && sum > maxSum)
            maxSum = sum;
        else if (minDiff >= abs(sum - 100))
        {
            maxSum = sum;
            minDiff = abs(sum - 100);
        }
    }
    cout << maxSum << "\n";
    return 0;
}