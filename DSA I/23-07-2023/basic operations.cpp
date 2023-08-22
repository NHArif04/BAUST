#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double var = 5.46, flr;
    flr = floor(var);
    int cl = (ceil(var)), reminder;
    reminder = cl % 2; // int var = 5 = floor
    cout << "Orignal value is: " << var << endl
         << "Floor value is: " << flr << endl
         << "Ceil value is: " << cl << endl
         << endl
         << "Reminder is: " << reminder; //mod
    return 0;
}