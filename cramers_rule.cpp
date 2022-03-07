#include <iostream>

using namespace std;
int main() {
    float a1, b1, c1;
    float a2, b2, c2;
    float delta, delta_x, delta_y;

    cout << "a1x + b1y = c1\n"; 
    cout << "Please input\na1:";
    cin >> a1;
    cout << "b1:";
    cin >> b1;
    cout << "c1:";
    cin >> c1;

    cout << "a2x + b2y = c2\n"; 
    cout << "Please input\na2:";
    cin >> a2;
    cout << "b2:";
    cin >> b2;
    cout << "c2:";
    cin >> c2;

    delta = a1*b2 - a2*b1;
    delta_x = c1*b2 - c2*b1;
    delta_y = a1*c2 - a2*c1;

    if(!delta) { // delta != 0
	if(delta_x == 0 && delta_y == 0) cout << "\nInfinite Solutions";
	else cout << "\nNo Solution";
    }
    else {
	cout << "\nx = " << delta_x / delta;
	cout << "\ny = " << delta_y / delta;
    }

    return 0;
}
