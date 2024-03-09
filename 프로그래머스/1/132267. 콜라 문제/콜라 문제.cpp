#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int curr = n;
    while (curr >= a) {
        answer += (curr / a) * b;
        curr = (curr / a) * b + curr % a;
    }
    return answer;
}