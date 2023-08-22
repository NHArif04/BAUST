#include<iostream>
using namespace std;

class Operator{
    public:
        int a;
        Operator(int x=0){
            a=x;
        }
        bool operator > (Operator temp){
            return a>temp.a;
        }

        bool operator < (Operator temp){
            return a<temp.a;
        }

        void operator ++ (int){  //post
            a++;
        }

        void operator ++ (){
            ++a;
        }

        void operator -- (int){  //post
            a--;
        }

        void operator -- (){
            --a;
        }

        void operator - (){
            a =- a;
        }

        Operator operator + (Operator temp){
            return  a+temp.a;
        }
};

void sign_change(Operator temp){
    cout<<temp.a<<endl;
}

void sign_change(Operator ob1, Operator ob2){
    cout<<ob1.a<<" "<<ob2.a<<endl;
}

int main(){
    Operator obj1(5), obj2(7), obj3;
    obj3 = obj1 + obj2;
    cout<<obj3.a<<endl;
    obj3++;
    cout<<obj3.a<<endl;
    obj3--;
    cout<<obj3.a<<endl;
    if(obj1>obj2){
        -obj1;
        sign_change(obj1);
    }else{
        -obj1;
        -obj2;
        sign_change(obj1,obj2);
    }
return 0;
}