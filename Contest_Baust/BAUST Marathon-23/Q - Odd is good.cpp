#include<iostream>
using namespace std;

int oddSum(int a, int b){
    int sum = 0;
    if(a>b) a^=b^=a^=b;
    while(a<=b){
        if(a%2) sum+=a;
        a++;
    }
    return sum;
}

int main(){
    int test, a, b;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin>>a>>b;
        int result = oddSum(a,b);
        cout<<"Case "<<i<<": "<<result<<endl;
    }
    return 0;
}