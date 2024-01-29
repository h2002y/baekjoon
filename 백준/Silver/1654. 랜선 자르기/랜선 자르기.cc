#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int K, N, cableCnt;
    long long start, mid, end, max = 0;
    cin>>K>>N;
    vector<long long> cable(K);
    for(int i = 0;i < K; i++) cin>>cable[i];
    sort(cable.begin(), cable.end());
    start = 1;
    end = cable.back();
    while(start <= end){
        mid = (start + end) / 2;
        cableCnt = 0;
        for(int i = 0; i < K; i++) cableCnt += (cable[i] / mid);
        if(cableCnt >= N){
            start = mid + 1;
            if(mid > max) max = mid;
        }
        else end = mid - 1;
    }
    cout<<max<<'\n';
    return 0;
}