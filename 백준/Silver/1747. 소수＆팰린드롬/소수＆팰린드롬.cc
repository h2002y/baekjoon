#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main () {
    int N, maxNum = 1003001;
    vector<bool> isPrime(maxNum, true);
    cin >> N;
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i <= maxNum; i += 2)
        isPrime[i] = false;
    for (int i = 3; i * i <= maxNum; i += 2) {
        if(isPrime[i]) {
            for (int j = i * i; j <= maxNum; j += i)
                isPrime[j] = false;
        }
    }
    for (int num = N; num <= maxNum; ++num) {
        if (!isPrime[num]) continue;
        string s = to_string(num);
        int left = 0, right = s.size() - 1;
        bool isPelin = true;
        while(left < right){
            if (s[left] != s[right]) {
                isPelin = false;
                break;
            }
            ++left;
            --right;
        }
        if (isPelin) {
            cout << num << "\n";
            break;
        }
    }
    return 0;
}