#include<bits/stdc++.h>
using namespace std;
class Increment{
    public:
        int first;
        Increment(int a){
            first = a;
        }
        void operator ++(int){ // return_type operator operator_sign(+) (parameter){}
            first ++;
        }
        void operator ++(){
            first++;
        }

};

int main(){
    Increment obj(2);
    cout<<obj.first++<<" "<<++obj.first<<endl;
    return 0;
}