#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
    int test, R1, R2, H, P;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin >>R1>>R2>>H>>P;
        double Rp = R2 + ((R1-R2)*P)/(H*1.0);
        double volume = (M_PI*P/3.0)*(pow(R2,2)+pow(Rp,2)+(R2*Rp));
        cout<<"Case "<<i<<": "<<fixed<<setprecision(9)<<volume<<endl;
    }
    return 0;
}