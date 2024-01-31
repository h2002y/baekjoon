#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<bool> isSelected;

void recurse(int depth, vector<int> selected, int next){
    if(depth == M){
        for(int i = 0; i < M; i++)
            cout << selected[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        if(isSelected[i]) continue;
        isSelected[i] = true;
        selected[depth] = i;
        recurse(depth + 1, selected, i + 1);
        selected[depth] = NULL;
        isSelected[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    vector<int> v(M, 0);
    isSelected.assign(N + 1, false);
    recurse(0, v, 1);
    return 0;
}