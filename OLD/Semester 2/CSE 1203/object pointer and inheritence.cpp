#include<iostream>
using namespace std;

class Parent{
    public:
        int x;
};

class Child : public Parent{
    public:
        int x;
};

int main(){
    Parent base, *bptr;
    Child derived, *dptr;
    bptr = &base;
    dptr = &derived;
    bptr->x = 1;
    dptr->x = 2;
    cout << "bptr->x = " << bptr->x << endl;
    cout << "dptr->x = " << dptr->x << endl;
    bptr = &derived;
    dptr = &base;
    return 0;
}