#include<iostream>
#include<cstdlib>
using namespace std;

class base{
    public:
        int i;
        base(int x){
            i=x;
        }

        void virtual func(){
            cout<<"Using base version of func()"<<endl;
            cout<<i<<endl;
        }
};

class derived1 : public base{
    public:
        derived1(int x):base(x){}
        void func(){
            cout<<"Using derived1's version of func()"<<endl;
            cout<<i*i<<endl;
        }
};

class derived2 : public base{
    public:
        derived2(int x):base(x){}
        void func(){
            cout<<"Using derived2's version of func()"<<endl;
            cout<<i+i<<endl;
        }
};

int main(){
    base *p;
    base ob(10);
    derived1 d1(20);
    derived2 d2(30);
    int i, j;

    for(i=0; i<10; i++){
        srand(time(0));
        j=rand();
        cout<<j<<endl;
        if(j%2) p = &d1;
        else p = &d2;
        p->func();
    }
return 0;
}