#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M;
    cin>>N;
    vector<int> cards(N);
    for(int i = 0; i < N; i++)
        cin >> cards[i];
    sort(cards.begin(), cards.end());
    cin >> M;
    for(int i = 0; i < M; i++){
        int find;
        cin>>find;
        int start = 0, end = N - 1;
        bool isFound = false;
        while(start <= end){
            int mid = (start + end) / 2;
            if(find == cards[mid]){
                cout<< 1 <<" ";
                isFound = true;
                break;
            }
            if(find > cards[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        if(!isFound)
            cout<< 0 << " ";
    }
    return 0;
}