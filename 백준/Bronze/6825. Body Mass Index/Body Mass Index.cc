#include <iostream>
using namespace std;

int main () {
    float W, H;
    cin >> W >> H;
    float BMI = W / (H * H);
    if (BMI > 25) cout << "Overweight\n";
    else if (BMI < 18.5) cout << "Underweight\n";
    else cout << "Normal weight\n";
    return 0;
}