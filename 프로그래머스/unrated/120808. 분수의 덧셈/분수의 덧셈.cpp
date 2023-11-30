#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);
    numer1 *= denom2;
    numer2 *= denom1;
    int sumNumer = numer1 + numer2;
    int sumDenom = denom1 * denom2;
    for(int i = 2; i <= sumDenom; i++) {
        while(sumNumer % i == 0 && sumDenom % i == 0) {
            sumNumer /= i;
            sumDenom /= i;
        }
    }
    answer[0] = sumNumer;
    answer[1] = sumDenom;
    return answer;
}