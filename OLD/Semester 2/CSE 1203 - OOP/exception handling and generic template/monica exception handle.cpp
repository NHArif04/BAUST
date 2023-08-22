#include <iostream>
using namespace std;

int main()
{
    double a, b, ans;
    cout << "Enter First Digit: ";
    cin >> a;
    cout << "Enter Second Digit: ";
    cin >> b;
    try {
        if (b == 0) {
            if (a == 0) {
                throw "Both digits are zero";
            }
            else {
                throw "Second digit is zero";
            }
        }
        ans = a / b;
        cout << "Answer is: " << ans;
    }
    catch (const char* ex) {
        cerr << "Exception caught: " << ex;
    }
    catch (...) {
        cerr << "Unknown exception caught";
    }
    return 0;
}
