#include<iostream>
using namespace std;

int main()
{
    char op;
    float num1, num2, result=0.0f;
    cin>>num1;
    cin>>op;
    cin>>num2;
    switch (op)
    {
    case '+':
        result = num1+num2;
        break;
    case '-':
        result = num1-num2;
        break;
    case '*':
        result = num1*num2;
        break;
    case '/':
        result = num1/num2;
        break;
    default:
        cout<<"invalid operation";
        break;
    }
    cout<<num1<<" "<<op<<" "<<num2<<" = "<<result;
    return 0;
}