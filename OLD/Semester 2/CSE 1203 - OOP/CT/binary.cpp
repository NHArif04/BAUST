#include<iostream>
using namespace std;

class object{
    public:
        int x;
        object(int a=0){           //default constructor initialized with default value
            x=a;                    
        }

        object operator + (object temp){    //return_type operator operator_sign (parameter){ body } 
            return x+temp.x;                //this prototype is for any operator overloading function
        }

        object operator * (object temp){
            return x*temp.x;
        }

        bool operator < (object temp){
            return x<temp.x;
        }
};

int main(){
    object obj1(4), obj2(7), obj3, obj4;
    obj3 = obj1 + obj2;
    obj4 = obj1 * obj2;
    cout<<obj3.x<<" "<<obj4.x<<endl;
    cout<<(obj3<obj4)<<endl;
return 0;
}

