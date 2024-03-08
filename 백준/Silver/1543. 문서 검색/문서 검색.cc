#include <iostream>
using namespace std;

int main()
{
    int cnt = 0;
    string s, f;
    getline(cin, s);
    getline(cin, f);
    if (s.size() < f.size())
    {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i <= s.size() - f.size(); ++i)
    {
        if (s[i] != f[0])
            continue;
        bool isMatch = true;
        for (int j = 1; j < f.size(); ++j)
        {
            if (s[i + j] != f[j])
            {
                isMatch = false;
                break;
            }
        }
        if (isMatch)
        {
            ++cnt;
            i = i + f.size() - 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}