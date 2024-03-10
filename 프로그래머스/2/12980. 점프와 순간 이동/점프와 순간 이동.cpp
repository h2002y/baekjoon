#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n)
{
    int curr = n, cnt = 0;
    while(curr > 0) {
        if (curr % 2 == 0)
            curr /= 2;
        else {
            --curr;
            ++cnt;
        }
    }
    return cnt;
}