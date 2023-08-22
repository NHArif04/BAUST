#include<bits/stdc++.h>
using namespace std;

class logical{
    int x;
    int y;
public:
    logical(int a,int b){
        x=a;
        y=b;
    }

    bool operator <(logical c);
        bool operator >(logical c) {
        return (x>c.x);
    }
};


int main(){
    logical Developer(5,5), Boss(8,0);
    Developer>Boss? cout<<"Boss"<<endl : cout<<"Developer"<<endl;
    return 0;
}