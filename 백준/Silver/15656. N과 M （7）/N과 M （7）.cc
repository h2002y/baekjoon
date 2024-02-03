#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> seq;

void recurse(int depth, vector<int> selected, int next){
    if(depth == M){
        for(int i = 0; i < M; i++)
            cout<<selected[i]<< " ";
        cout<<"\n";
        return;
    }
    for(int i = next; i < N; i++){
        selected[depth] = seq[i];
        recurse(depth + 1, selected, next);
        selected[depth] = NULL;
    }
}

int main(){
    cin >> N >> M;
    seq.assign(N, NULL);
    for(int i = 0; i < N; i++)
        cin >> seq[i];
    sort(seq.begin(), seq.end());
    vector<int> v(M);
    recurse(0, v, 0);
    return 0;
}