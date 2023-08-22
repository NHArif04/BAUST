#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n1, n2;

    cout << "Enter the two numbers you want to find the GCD and LCM of: ";
    cin >> n1 >> n2;

    cout << "The GCD of the two numbers: " << n1 << " and " << n2 << " is: " << gcd(n1, n2) << endl;
    cout << "The LCM of the two numbers: " << n1 << " and " << n2 << " is: " << lcm(n1, n2);

    return 0;
}
