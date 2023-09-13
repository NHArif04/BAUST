#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

typedef struct{
    double x,y;
}coordinate;

int main(){
    int test;
    cin>>test;
    coordinate o, a, b;
    double result, radius, straight;
    for(int i=1; i<=test; i++){
        cin>>o.x>>o.y>>a.x>>a.y>>b.x>>b.y;
        straight = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
        radius = sqrt(pow(a.x-o.x,2)+pow(a.y-o.y,2));
        result = 2*radius*asin(straight/(2*radius));
        cout<<"Case "<<i<<": "<<fixed<<setprecision(6)<<result<<endl;
    }
    return 0;
}