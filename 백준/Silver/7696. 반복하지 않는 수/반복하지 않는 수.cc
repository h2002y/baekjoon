#include <iostream>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> nums(1000001);
    int index = 1, n = 1;
    while (index < 1000001) {
        bool isSingle = true;
        vector<int> m(10);
        int num = n;
        while (num != 0) {
            m[num % 10]++;
            if(m[num % 10] > 1) {
                isSingle = false;
                break;
            }
            num /= 10;
        }
        if(!isSingle) {
            n++;
            continue;
        }
        nums[index] = n;
        n++;
        index++;
    }
    int input;
    while(1) {
        cin >> input;
        if (input == 0) break;
        cout << nums[input] << "\n";
    }
    return 0;
}