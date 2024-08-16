#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    int currTruck = 0, currSec = 0, currWeight = 0, currTruckOnBridge = 0;
    while(!(currTruck >= truck_weights.size() && q.empty())) {
        ++currSec;
        if (!q.empty() && currSec > bridge_length) {
            int truckCrossed = q.front();
            q.pop();
            if (truckCrossed != -1) {
                currWeight -= truck_weights[truckCrossed];
                currTruckOnBridge--;
            }
        }
        // 건너야할 트럭이 남아있으면 && 다리 칸에 여유가 있으면
        if (currTruck < truck_weights.size() && currTruckOnBridge < bridge_length) {
            // 다리가 트럭 무게를 감당할 수 있으면
            if (currWeight + truck_weights[currTruck] <= weight) {
                currWeight += truck_weights[currTruck];
                currTruckOnBridge++;
                q.push(currTruck++);
            } else {
                q.push(-1);
            }
        }
    }
    return currSec;
}