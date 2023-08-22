#include<bits/stdc++.h>
using namespace std;
class Multiply{
    public:
        int first, second, third;
        Multiply(int a=0, int b=0,int c=0){
            first = a;
            second = b;
            third = c;
        }
        Multiply operator * (Multiply c){
            return Multiply(first * c.first, second * c.second, third * c.third);
            // Multiply temp(0,0,0);
            // temp.first = first * c.first;
            // temp.second = second * c.second;
            // temp.third = third * c.third;
            // return temp;
        }
};

int main(){
    Multiply obj1(2,4,3), obj2(5,6,2), obj3(8,7,9), obj4(2,4,2);
    obj3 = (obj2 * obj1)*obj4;
    cout<<obj3.first<<" "<<obj3.second<<" "<<obj3.third<<endl;
    return 0;
}