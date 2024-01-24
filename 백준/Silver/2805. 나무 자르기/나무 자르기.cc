#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long N, M, max = 0, start, end, mid, sum;
    cin>>N>>M;
    vector<int> logs(N);
    for(int i = 0; i < N; i++) cin>>logs[i];
    sort(logs.begin(), logs.end());
    start = 0;
    end = logs.back();
    while(start <= end){
        sum = 0;
        mid = (start + end) / 2;
        for(int i = 0; i < N; i++)
            if(logs[i] > mid) sum += logs[i] - mid;
        if(sum >= M){
            start = mid + 1;
            if(mid > max) max = mid;
        }
        else end = mid - 1;
    }
    cout<<max<<"\n";
    return 0;
}