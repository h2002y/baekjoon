#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, answer = 0;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cin >> x;

    sort(v.begin(), v.end());
    int left = 0;
    int right = v.size() - 1;
    while (left < right)
    {
        int curr = v[left] + v[right];
        if (curr == x)
        {
            answer++;
            left++;
            right--;
        }
        else if (curr < x)
            left++;
        else
            right--;
    }
    cout << answer << "\n";
    return 0;
}