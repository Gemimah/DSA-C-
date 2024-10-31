#include<iostream>
using namespace std;

int amount=5000;
int main() {
int amount=3000;
cout<<"The local amount is"<<amount<<endl;
cout<<"The Global amount is "<<::amount<<endl;
return 0;
}
