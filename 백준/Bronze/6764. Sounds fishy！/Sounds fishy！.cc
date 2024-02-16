#include <iostream>
using namespace std;

int main () {
    int depth[4];
    for (int i = 0; i < 4; ++i)
        cin >> depth[i];
    if (depth[0] < depth[1] && depth[1] < depth[2] & depth[2] < depth[3])\
        cout << "Fish Rising\n";
    else if (depth[0] > depth[1] && depth[1] > depth[2] && depth[2] > depth[3])
        cout << "Fish Diving\n";
    else if (depth[0] == depth[1] && depth[1] == depth[2] && depth[2] == depth[3])
        cout << "Fish At Constant Depth\n";
    else cout << "No Fish\n";
    return 0;
}