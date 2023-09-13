#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    double radius;
    for(int i=1; i<=test; i++){
        cin>>radius;
        double area = pow(radius*2,2) - 2*acos(0.0)*pow(radius,2);
        cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<area<<endl;
    }
    return 0;
}