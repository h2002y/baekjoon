#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, sum = 0;
    cin>>N>>M;
    vector<int> numbers(N), sums(N);
    for(int i = 0; i < N; i++){
        cin>>numbers[i];
        sum += numbers[i];
        sums[i] = sum;
    }
    for(int i = 0; i < M; i++){
        int left, right;
        cin>>left>>right;
        if(left == 1) cout<<sums[right-1]<<"\n";
        else cout<<sums[right - 1] - sums[left - 2]<<"\n";
    }
    return 0;
}