#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int left = 0, right = 0;
    int sum = sequence[0], len = sequence.size() + 1;
    while(left <= right && right < sequence.size()) {
        if(sum == k) {
            if(right - left + 1 < len) {
                len = right - left + 1;
                answer = {left, right};
            }
            else if(right - left + 1 == len && left < answer[0]) {
                answer = {left, right};
            }
            sum -= sequence[left++];
        } 
        else if (sum < k)
            sum += sequence[++right];
        else {
            sum -= sequence[left++];
        }
    }

    return answer;
}