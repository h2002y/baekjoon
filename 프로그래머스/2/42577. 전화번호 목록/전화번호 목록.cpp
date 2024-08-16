#include <string>
#include <vector>
#include <set>

#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> isExist;
    bool answer = true;
    for(int i = 0; i < phone_book.size(); ++i) {
        for (int j = 1; j < phone_book[i].length(); ++j) {
            string tmp = phone_book[i].substr(0, j);
            isExist.insert(tmp);
        }
    }
    for (int i = 0; i < phone_book.size(); ++i) {
        if (isExist.find(phone_book[i]) != isExist.end()) {
            answer = false;
            break;
        }
    }
    return answer;
}