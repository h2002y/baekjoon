#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int N, int K){
    vector<int> seconds(100001, -1);
    queue<int> q;
    q.push(N);
    seconds[N] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == K)
            return seconds[curr];
        if(0 <= curr && curr < 100000){
            if(seconds[curr + 1]  == -1){
                seconds[curr + 1] = seconds[curr] + 1;
                q.push(curr + 1);
            }
        }
        if(curr > 0 && curr <= 100000){
            if(seconds[curr - 1] == -1){
                seconds[curr - 1] = seconds[curr] + 1;
                q.push(curr - 1);
            }
        }
        if(curr >= 0 && curr <= 50000){
            if(seconds[curr * 2] == -1){
                seconds[curr * 2] = seconds[curr] + 1;
                q.push(curr * 2);
            }
        }      
    }
}

int main(){
    int N, K;
    cin>>N>>K;
    cout<<bfs(N, K)<<endl;
    return 0;
}