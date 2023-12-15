#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int tc = 1; tc <= N; ++tc) {
        int A, B;
        cin >> A >> B;
        cout << "Case #" << tc << ": " << A + B << "\n";
    }
    return 0;
}