#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length() - 1; ++i)
    {
        int j = i + 1;
        if (s[i] == 'X' && s[j] == 'X')
        {
            s[i] = s[j] = 'B';
            i += 1;
        }
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'X')
        {
            cout << "-1\n";
            return 0;
        }
    }
    if (s.length() < 4)
    {
        cout << s << "\n";
        return 0;
    }
    for (int i = 0; i < s.length() - 3; ++i)
    {
        int j = i + 1, k = i + 2, l = i + 3;
        if (s[i] == 'B' && s[j] == 'B' && s[k] == 'B' && s[l] == 'B')
        {
            s[i] = s[j] = s[k] = s[l] = 'A';
            i += 3;
        }
    }
    cout << s << endl;
    return 0;
}