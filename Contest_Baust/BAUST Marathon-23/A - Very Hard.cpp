#include<iostream>
using namespace std;

int main(){
    int test, a, b;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin>>a>>b;
        cout<<"Case "<<i<<": "<<a+b<<endl;
    }
    return 0;
}