#include<iostream>
#include<limits>
using namespace std;

int factorial(int n){
    if ( n <= 1 )
        return 1 ;
    return n * factorial(n-1);
}

int main(){
    int number{};   //number = 0 is same
    cin>>number;
    cout<<"Factorial of "<<number<<": "<<factorial(number);
    return 0;
}