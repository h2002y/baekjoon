#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<bool> isSelected;
vector<int> seq;

void recurse(int depth, vector<int> selected){
    if(depth == M){
        for(int i = 0; i < M; i++)
            cout << selected[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < N; i++){
        if(isSelected[i]) continue;
        isSelected[i] = true;
        selected[depth] = seq[i];
        recurse(depth + 1, selected);
        selected[depth] = NULL;
        isSelected[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    seq.assign(N, 0);
    for(int i = 0; i < N; i++)
        cin >> seq[i];
    vector<int> v(M, 0);
    isSelected.assign(N + 1, false);
    sort(seq.begin(), seq.end());
    recurse(0, v);
    return 0;
}