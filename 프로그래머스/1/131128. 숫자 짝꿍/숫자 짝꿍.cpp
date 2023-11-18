#include <string>
#include <vector>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> numX(10), numY(10);
    for(int i = 0; i < X.length(); i++) 
        numX[X[i] - '0']++;
    
    for(int i = 0; i < Y.length(); i++)
        numY[Y[i] - '0']++;
    bool isZero = true;
    for(int i = 9; i >= 0; i--) {
        int minCount = min(numX[i], numY[i]);
        if(i != 0 && minCount > 0) isZero = false;
        for(int j = 0; j < minCount; j++)
            answer += (i + '0');
        if(i == 0 && isZero && minCount > 0) answer = "0";
    }
    if(answer == "") answer = "-1";
    return answer;
}