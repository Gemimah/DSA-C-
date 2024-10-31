#include <iostream>
using namespace std;

struct Rectangle {

private:
    int width;
    int length;

public:
    Rectangle() {}
    Rectangle(int w, int l) {
        width = w;
        length = l;
    }

    int area() {
        return width * length;
    }

    void setWidth(int w) {
        width = w;
    }

    int getWidth() {
        return width;
    }

    void setBoth(int w, int l) {
        width = w;
        length = l;
    }
};


int main() {
    Rectangle rect(10, 20);
    cout << "area is " << rect.area() << endl;
    Rectangle rectb;
    rectb.setBoth(20,30);
    cout<<"Area is"<<rect.area()<<endl;
    Rectangle *rectc=new Rectangle(100,300);
    cout<<"Area in c is"<<rectc->area()<<endl
cout<<"The width
    return 0;
}
