#include <iostream>
#include <vector>
#include <string>
using namespace std;

static string maxAns = "0", minAns = "9999999999";
static int N, len;
vector<bool> isSelected(10);
vector<char> sign;

void recurse(int depth, string selected){
    if(depth == len){
        if(maxAns < selected)
            maxAns = selected;
        if(minAns > selected)
            minAns = selected;
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(isSelected[i]) continue;
        switch (sign[depth-1])
        {
        case '<':
            if(selected.back() - '0' < i){
                isSelected[i] = true;
                selected.push_back((char)(i + '0'));
                recurse(depth + 1, selected);
                isSelected[i] = false;
                selected.pop_back();
            }
            break;
        
        case '>':
            if(selected.back() - '0' > i){
                isSelected[i] = true;
                selected.push_back((char)(i + '0'));
                recurse(depth + 1, selected);
                isSelected[i] = false;
                selected.pop_back();
            }
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string selected = "";
    cin>>N;
    len = N + 1;
    sign.assign(N, ' ');
    for(int i = 0; i < N; i++)
        cin>>sign[i];

    for(int i = 0; i <= 9; i++){
        selected.push_back((char)(i + '0'));
        isSelected[i] = true;
        recurse(1, selected);
        isSelected[i] = false;
        selected.pop_back();
    }
    cout<<maxAns<<"\n"<<minAns<<"\n";
    return 0;
}