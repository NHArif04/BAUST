#include <iostream>
using namespace std;
class Unary
{
public:
    int num, num2;
    Unary(int a, int b){
        num = a;
        num2 = b;
    }
    void operator - ()
    {
        num =- num;
        num2 =- num2;
    }
};

int main()
{
    Unary numbers(-40,29);
    -numbers; // calling of a function "void operator ++()"
    cout<<numbers.num<<" "<<numbers.num2<<endl;
    return 0;
}