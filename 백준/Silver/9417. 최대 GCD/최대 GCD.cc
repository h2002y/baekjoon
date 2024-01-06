#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    cin.ignore();
    for (int tc = 0; tc < T; ++tc) {
        int maxGcd = 0;
        vector<int> M;
        string str;
        getline(cin, str);
        stringstream ss(str);
        string number;
        while (getline(ss, number, ' ')) M.push_back(stoi(number));
        for (int i = 0; i < M.size(); ++i) {
            for (int j = i + 1; j < M.size(); ++j) {
                int tmpGcd = gcd(M[i], M[j]);
                if (maxGcd < tmpGcd) maxGcd = tmpGcd;
            }
        }
        cout << maxGcd << "\n";
    }
    return 0;
}