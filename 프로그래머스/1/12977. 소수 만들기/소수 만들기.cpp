#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<bool> isPrime(3000, true);
    for (int i = 2; i * i <= 3000; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 3000; j += i)
                isPrime[j] = false;
        }
    } 
    for (int i = 0; i < nums.size() - 2; ++i)
        for (int j = i + 1; j < nums.size() - 1; ++j)
            for (int k = j + 1; k < nums.size(); ++k)
                if (isPrime[nums[i] + nums[j] + nums[k]])
                    ++answer;

    return answer;
}