#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int test, a, b, c;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin>>a>>b>>c;
        string result = (a>=b+c || b>=a+c || c>=a+b)?"Wrong!!":"OK";
        cout<<result<<endl;
    }
    return 0;
}