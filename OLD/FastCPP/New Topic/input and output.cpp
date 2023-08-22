#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int a{};  //->initialize with zero
    double d{1.5}; //->initialize with 1.5
    cout<<a<<" "<<d<< endl;
    cin>>a>>d;  //->10.5 will be divide => a=10 b=0.5
    cout<<a<<" "<<d<< endl;
    return 0;
}