#include <iostream>
#include <vector>
using namespace std;

typedef struct answer {
    string num;
    int strike;
    int ball;
} Answer;

int main () {
    int N, cnt = 0;
    cin >> N;
    vector<Answer> answers(N);
    for (int i = 0; i < N; ++i)
        cin >> answers[i].num >> answers[i].strike >> answers[i].ball;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i == j) continue;
            for (int k = 1; k <= 9; ++k) {
                if (i == k || j == k) continue;
                // 예측 숫자 [ i j k ] 3개 뽑음

                bool isMatch = true;

                // 예측 숫자를 대답과 비교
                for (int n = 0; n < N; ++n) {
                    int tmpStrike = 0, tmpBall = 0;
                    for (int l = 0; l < 3; ++l) {
                        // 첫번째 숫자와 비교
                        if (l == 0 && i == answers[n].num[0] - '0') ++tmpStrike;
                        else if (i == answers[n].num[l] - '0') ++tmpBall;
                        // 두번째 숫자와 비교
                        if (l == 1 && j == answers[n].num[1] - '0') ++tmpStrike;
                        else if (j == answers[n].num[l] - '0') ++tmpBall;
                        // 세번째 숫자와 비교
                        if (l == 2 && k == answers[n].num[2] - '0') ++ tmpStrike;
                        else if (k == answers[n].num[l] - '0') ++tmpBall;
                    }
                    if(tmpStrike != answers[n].strike || tmpBall != answers[n].ball) isMatch = false;
                }
                if(isMatch) ++cnt;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}