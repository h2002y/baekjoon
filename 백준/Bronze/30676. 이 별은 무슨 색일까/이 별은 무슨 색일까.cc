#include <iostream>
using namespace std;

int main() {
    int input;
    cin >> input;
    if(620 <= input && input <= 780)
        cout << "Red\n";
    else if(590 <= input && input < 620)
        cout << "Orange\n";
    else if(570 <= input && input < 590)
        cout << "Yellow\n";
    else if(495 <= input && input < 570)
        cout << "Green\n";
    else if(450 <= input && input < 495)
        cout << "Blue\n";
    else if(425 <= input && input < 450)
        cout << "Indigo\n";
    else cout <<"Violet\n";
    return 0;
}