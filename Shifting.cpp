#include <iostream>
using namespace std;

int main() {
    int a = 75;
    int k = a >> 2;
    int d = a << 1;
    #define PI 3.14
    const double PI2=3.14;

    cout << "k = " << k << endl;
    cout << "d = " << d << endl;
    cout << "PI2 = "<< PI2 << endl;
    cout << "PI = " << PI << endl;

    return 0;
}
