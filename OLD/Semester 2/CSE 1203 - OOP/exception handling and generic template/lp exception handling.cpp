#include <iostream>
using namespace std;

int main() {
    try {
        double num1;
        cout <<"Enter the first number:";
        cin >> num1;
        
        double num2;
        cout <<"Enter the second number:";
        cin >> num2;
    
        if(num2 == 0.0) {
            throw 0.0;
        }
    
        cout <<"Result:"<<num1 / num2;
    }
    
    
    catch(...) {
        cout <<"You cannot divide any number by zero! Because in ordinary arithmetic, the expression has no meaning, as there is no number which, when multiplied by 0, gives a (assuming a ≠ 0), and so division by zero is undefined.";
    }
    
    return 0;
}