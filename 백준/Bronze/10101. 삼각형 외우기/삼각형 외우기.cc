#include <iostream>
using namespace std;

int main () {
    int t1, t2, t3, sum = 0;
    cin >> t1 >> t2 >> t3;
    sum = t1 + t2 + t3;
    if (t1 == 60 && t2 == 60 && t3 == 60)
        cout << "Equilateral\n";
    else if (sum == 180 && (t1 == t2 || t1 == t3 || t2 == t3))
        cout << "Isosceles\n";
    else if (sum == 180 && t1 != t2 && t2 != t3 && t1 != t3)
        cout << "Scalene\n";
    else cout << "Error\n";
    return 0;
}