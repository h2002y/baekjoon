#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, char>> tree(26);

void preOrder(char curr) {
    if (curr == '.') return;
    int currIdx = curr - 'A';
    cout << curr;
    preOrder(tree[currIdx].first);
    preOrder(tree[currIdx].second);
}

void inOrder(char curr) {
    if (curr == '.') return;
    int currIdx = curr - 'A';
    inOrder(tree[currIdx].first);
    cout << curr;
    inOrder(tree[currIdx].second);
}

void postOrder(char curr) {
    if (curr == '.') return;
    int currIdx = curr - 'A';
    postOrder(tree[currIdx].first);
    postOrder(tree[currIdx].second);
    cout << curr;
}

int main () {
    int N;
    cin >> N;
    
    // 트리 입력
    for (int i = 0; i < N; ++i) {
        char p, c1, c2;
        cin >> p >> c1 >> c2;
        tree[p - 'A'].first = c1;
        tree[p - 'A'].second = c2;
    }
    
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";

    return 0;
}