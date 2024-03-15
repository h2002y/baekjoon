#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, INF = 200001;
vector<int> dots(INF, -1);

int main()
{
    cin >> N >> K;
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));

    while (!q.empty())
    {
        int curr = q.front().first;
        int time = q.front().second;
        q.pop();
        if (dots[curr] != -1 && time >= dots[curr])
            continue;
        dots[curr] = time;

        if (curr * 2 < INF && (dots[curr * 2] == -1 || (dots[curr * 2] != -1 && dots[curr * 2] > time)))
            q.push(make_pair(curr * 2, time));
        if (curr + 1 < INF && (dots[curr + 1] == -1 || (dots[curr + 1] != -1 && dots[curr + 1] > time)))
            q.push(make_pair(curr + 1, time + 1));
        if (curr - 1 >= 0 && (dots[curr - 1] == -1 || (dots[curr - 1] != -1 && dots[curr - 1] > time)))
            q.push(make_pair(curr - 1, time + 1));
    }
    cout << dots[K] << "\n";
    return 0;
}