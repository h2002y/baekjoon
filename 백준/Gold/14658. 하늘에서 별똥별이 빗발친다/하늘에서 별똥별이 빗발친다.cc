#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M, L, K;
    cin >> N >> M >> L >> K;
    vector<int> X(K), Y(K);
    for (int i = 0; i < K; ++i)
        cin >> X[i] >> Y[i];
    int maxStar = 0;
    for (int i = 0; i < K; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            int y = Y[i];
            int x = X[j];
            int star = 0;
            for (int k = 0; k < K; ++k)
            {
                int ny = Y[k];
                int nx = X[k];
                if (y <= ny && ny <= y + L && x <= nx && nx <= x + L)
                    ++star;
            }
            if (star > maxStar)
                maxStar = star;
        }
    }
    cout << K - maxStar << "\n";
    return 0;
}