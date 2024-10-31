#include<iostream>
using namespace std;

namespace userDefined {
    int money = 5000;


    int customCout() {
        return money;
    }
}

int myGlobal = 5;


int customCout() {
    return myGlobal * 5 * 8;
}

int main() {
    int localCout = 3000;


    cout << "The local variable Cout in main is: " << localCout << endl;
    cout << "The global variable myGlobal is: " << myGlobal << endl;
    cout << "The variable in userDefined namespace is: " << userDefined::money << endl;
    cout << "The value of myGlobal * 5 * 8 is: " << customCout() << endl;

    return 0;
}
