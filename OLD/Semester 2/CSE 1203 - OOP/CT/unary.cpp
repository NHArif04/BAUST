#include<iostream>
using namespace std;

class object{
    public:
        int x;
        object(int a){
            x = a;
        }

        void operator ++(){  //this is pre-increment
            ++x;
        }

        void operator ++ (int){  //this is post-increment
            x++;
        }

        void operator - (){      //this operator overloading function is used to change sign of a variable
            x=-x;
        }
};

int main(){
    object obj1(2), obj2(8);
    cout<<obj1.x<<endl;
    obj1++;
    cout<<obj1.x<<endl;
    cout<<obj2.x<<endl;
    -obj2;
    cout<<obj2.x<<endl;
return 0;
}