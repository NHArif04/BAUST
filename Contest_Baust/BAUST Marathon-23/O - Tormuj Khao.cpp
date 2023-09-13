#include<iostream>
using namespace std;

int main(){
    int w;
    cin>>w;
    string result = w%2==0 && w>2?"YES":"NO";
    cout<<result<<endl;
    return 0;
}