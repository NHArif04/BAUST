#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int test, a, b, c;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin>>a>>b>>c;
        string result = (pow(a,2) == pow(b,2) + pow(c,2) || pow(b,2) == pow(a,2) + pow(c,2) || pow(c,2) == pow(a,2) + pow(b,2))?"yes":"no";
        cout<<"Case "<<i<<": "<<result<<endl;
    }
    return 0;
}