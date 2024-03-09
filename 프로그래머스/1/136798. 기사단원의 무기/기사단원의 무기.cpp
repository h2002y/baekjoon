#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> divisor(number + 1);
    for (int i = 1; i <= number; ++i) {
        for (int j = i; j <= number; j += i)
            divisor[j]++;
    }
    for (int k = 1; k <= number; ++k) {
        if (divisor[k] > limit) answer += power;
        else answer += divisor[k];
    }
    return answer;
}