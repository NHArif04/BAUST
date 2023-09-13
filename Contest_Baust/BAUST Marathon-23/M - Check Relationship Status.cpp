#include<iostream>
using namespace std;

int main(){
    int test, a, b;
    cin>>test;
    while(test--){
        cin>>a>>b;
        char result = a>b?'>':a<b?'<':'=';
        cout<<result<<endl;
    }
    return 0;
}