#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

static int N, maxAns;
vector<int> input;
vector<bool> isSelected;

void recurse(int depth, int sum, int prev){
    if(depth == N){
        maxAns = max(maxAns, sum);
        return;
    }
    for(int i = 0; i < N; i++){
        if(isSelected[i]) continue;
        int result = abs(prev - input[i]);
        isSelected[i] = true;
        sum += result;
        recurse(depth + 1, sum, input[i]);
        sum -= result;
        isSelected[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    input.assign(N, 0);
    isSelected.assign(N, false);
    for(int i = 0; i < N; i++)
        cin>>input[i];
    for(int i = 0; i < N; i++){
        isSelected[i] = true;
        recurse(1, 0, input[i]);
        isSelected[i] = false;
    }
    cout<<maxAns<<"\n";
    return 0;
}