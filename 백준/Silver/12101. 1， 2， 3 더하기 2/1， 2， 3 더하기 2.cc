#include <iostream>
#include <string>
using namespace std;

int N, K, cnt;
bool isFound;

void recurse (int sum, string tmp) {
    if(sum > N || cnt > K) return;
    if(sum == N) {
        ++cnt;
        if(cnt == K) {
            cout << tmp << "\n";
            isFound = true;
        }
    }
    for (int i = 1; i <= 3; ++i) {
        if (tmp == "") recurse(sum + i, tmp + to_string(i));
        else recurse(sum + i, tmp + "+" + to_string(i));
    }
}

int main () {
    cin >> N >> K;
    string tmp = "";
    recurse(0, tmp);
    if (!isFound) cout << "-1\n";
    return 0;
}