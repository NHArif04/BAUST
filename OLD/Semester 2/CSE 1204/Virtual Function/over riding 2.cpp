#include<iostream>
using namespace std;

class base{
    public:
        int i;
        base(int x){i=x;}
        inline void virtual func(){cout<<i<<endl;}
};
class derived1 : public base{
    public:
        derived1(int x):base(x){}
        inline void func(){cout<<i*i<<endl;}
};
class derived2 : public base{
    public:
        derived2(int x):base(x){}
};

int main(){
    base *p;
    base ob(10);
    derived1 d1(20);
    derived2 d2(30);
    p=&ob;
    p->func();
    p=&d1;
    p->func();
    p=&d2;
    p->func();
return 0;
}