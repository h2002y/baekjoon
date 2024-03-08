#include <iostream>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    for (int i = -1000; i <= 1000; ++i)
    {
        if (i * i + 2 * A * i + B == 0)
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}