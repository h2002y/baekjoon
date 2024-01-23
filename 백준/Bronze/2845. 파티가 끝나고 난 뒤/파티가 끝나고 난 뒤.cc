#include <iostream>
using namespace std;

int main () {
    int area, ppl, totalPpl;
    cin >> area >> ppl;
    totalPpl = area * ppl;
    for (int i = 0; i < 5; ++i) {
        int newsPpl;
        cin >> newsPpl;
        cout << newsPpl - totalPpl << " ";
    }
    return 0;
}