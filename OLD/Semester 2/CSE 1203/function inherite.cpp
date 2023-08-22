#include <iostream>
using namespace std;
class Test
{
private:
    int number, number2;

public:
    Test() : number(8), number2(9) {} // default variable set to variable using ..
    void operator++()
    {
        number = number + 2;
        number2 = number2 + number;
    }
    void Print()
    {
        cout << "The Count is: " << number << ends << number2;
    }
};

int main()
{
    Test tt;
    ++tt; // calling of a function "void operator ++()"
    tt.Print();
    return 0;
}