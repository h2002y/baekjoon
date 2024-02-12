#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, inputChannel, numOfClick;
    cin >> inputChannel >> N;
    numOfClick = abs(100 - inputChannel);
    vector<bool> broken(10, false);
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        broken[input] = true;
    }
    for(int channel = 0; channel <= 999999; channel++) {
		string currChannel = to_string(channel);
		int currLen = currChannel.length();
			
		bool isBroken = false;
		for(int i = 0; i < currLen; i++) {
			if(broken[currChannel[i] - '0']) {
				isBroken = true;
				break;
			}
		}
		if(isBroken) continue;
		int click = abs(channel - inputChannel) + currLen;
		numOfClick = min(numOfClick, click);
	}
    cout<<numOfClick<<"\n";
}