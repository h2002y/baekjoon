#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); ++i)
        pq.push(scoville[i]);
    while(true) {
        int curr = pq.top();
        pq.pop();
        if (curr < K) {
            if (pq.empty()) {
                answer = -1;
                break;
            }
            int next = pq.top();
            pq.pop();
            pq.push(curr + (next * 2));
            ++answer;
        } else break;
    }
    return answer;
}