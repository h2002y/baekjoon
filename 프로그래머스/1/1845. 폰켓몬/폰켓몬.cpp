#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    int answer = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(s.find(nums[i]) == s.end()) {
            ++answer;
            s.insert(nums[i]);
        }
    }
    if (answer > nums.size() / 2) answer = nums.size() / 2;
    return answer;
}