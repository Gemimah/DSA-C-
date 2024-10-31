#include <iostream>
using namespace std;

#define PI 3.14
const double PI2 = 3.14;

double area(int radius) {
    return radius * radius * PI;
}

int main() {
    int radius;
    cout << "Enter the radius: ";
    cin >> radius;


    cout << "The area is " << area(radius) << endl;

    return 0;
}
