#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter a digit to check: ";
    cin>>num;
    cout<<"Number is "<<(num%2?"odd":"even");
    return 0;
}