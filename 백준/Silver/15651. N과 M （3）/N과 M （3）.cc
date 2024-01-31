#include <iostream>
#include <vector>
using namespace std;

int N, M;

void recurse(int depth, vector<int> selected, int next){
    if(depth == M){
        for(int i = 0; i < M; i++)
            cout<<selected[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        selected[depth] = i;
        recurse(depth + 1, selected, i);
        selected[depth] = 0;
    }
}

int main(){
    cin >> N >> M;
    vector<int> v(M, 0);
    recurse(0, v, 1);
    return 0;
}